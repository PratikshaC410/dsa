#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n, m;
    long long h;
    cin >> n >> m >> h;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    vector<pair<int, long long>> ops(m + 1);
    for (int i = 1; i <= m; ++i)
    {
        cin >> ops[i].first >> ops[i].second;
    }

    // tracks the operation index when the array was last reset for each element
    vector<int> last_reset_at(n + 1, 0);
    // tracks the accumulated value added to an element SINCE its last reset
    vector<long long> added_since_reset(n + 1, 0);

    int global_last_crash = 0;

    //  Find the absolute final crash point
    for (int i = 1; i <= m; ++i)
    {
        int idx = ops[i].first;
        long long val = ops[i].second;

        // If the last global crash happened AFTER this specific element was touched,
        // it means this element was virtually reset to original. We must clear its history.
        if (last_reset_at[idx] < global_last_crash)
        {
            added_since_reset[idx] = 0;
            last_reset_at[idx] = global_last_crash;
        }

        // Add the current operation's value to its history since the last crash
        added_since_reset[idx] += val;

        // Check if the original value + everything added since the last crash exceeds h
        if (a[idx] + added_since_reset[idx] > h)
        {
            global_last_crash = i;      // Mark this as the latest global crash
            added_since_reset[idx] = 0; // Since it crashed, this element resets immediately
            last_reset_at[idx] = i;     // Update its local tracking timestamp
        }
    }

    for (int i = global_last_crash + 1; i <= m; ++i)
    {
        int idx = ops[i].first;
        long long val = ops[i].second;
        a[idx] += val;
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << a[i] << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}