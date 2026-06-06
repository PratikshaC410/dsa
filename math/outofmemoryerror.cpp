#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n, m;
    long long h;
    cin >> n >> m >> h;

    vector<long long> original_a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> original_a[i];
    }

    vector<pair<int, long long>> ops(m + 1);
    for (int i = 1; i <= m; ++i)
    {
        cin >> ops[i].first >> ops[i].second;
    }

    vector<long long> current_a = original_a;
    int last_crash_idx = 0;

    for (int i = 1; i <= m; ++i)
    {
        int idx = ops[i].first;
        long long val = ops[i].second;

        current_a[idx] += val;

        if (current_a[idx] > h)
        {
            last_crash_idx = i;

            current_a = original_a;
        }
    }

    for (int i = last_crash_idx + 1; i <= m; ++i)
    {
        int idx = ops[i].first;
        long long val = ops[i].second;
        original_a[idx] += val;
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << original_a[i] << (i == n ? "" : " ");
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