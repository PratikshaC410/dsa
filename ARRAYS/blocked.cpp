#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    vector<bool> used(n, false);
    vector<int> result;

    int max_sum = 20005;
    vector<bool> reachable(max_sum, false);
    reachable[0] = true; // Base case

    for (int step = 0; step < n; ++step)
    {
        int found_idx = -1;

        for (int i = 0; i < n; ++i)
        {
            if (!used[i] && !reachable[a[i]])
            {
                found_idx = i;
                break;
            }
        }

        if (found_idx == -1)
        {
            cout << -1 << "\n";
            return;
        }

        used[found_idx] = true;
        int val = a[found_idx];
        result.push_back(val);
        for (int sum = max_sum - 1; sum >= val; --sum)
        {
            if (reachable[sum - val])
            {
                reachable[sum] = true;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        cout << result[i] << (i == n - 1 ? "" : " ");
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