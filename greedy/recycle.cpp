#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void solve()
{
    int n;
    long long c;
    cin >> n >> c;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> dp(n + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < n; ++i)
    {
        vector<int> next_dp(n + 1, INF);
        for (int j = 0; j <= i; ++j)
        {
            if (dp[j] == INF)
                continue;

            next_dp[j] = min(next_dp[j], dp[j] + 1);

            long long current_weight = a[i];
            bool overflow = false;
            for (int k = 0; k < j; ++k)
            {
                if (current_weight > c)
                {
                    overflow = true;
                    break;
                }
                current_weight *= 2;
            }

            if (!overflow && current_weight <= c)
            {
                next_dp[j + 1] = min(next_dp[j + 1], dp[j]);
            }
            else
            {
                next_dp[j + 1] = min(next_dp[j + 1], dp[j] + 1);
            }
        }
        dp = move(next_dp);
    }

    int ans = INF;
    for (int j = 0; j <= n; ++j)
    {
        ans = min(ans, dp[j]);
    }

    cout << ans << "\n";
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