#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

void solve()
{
    long long r0, x, d, n;
    cin >> r0 >> x >> d >> n;
    string s;
    cin >> s;

    vector<long long> dp(n + 1, INF);
    dp[0] = r0;

    for (char type : s)
    {
        vector<long long> next_dp(n + 1, INF);
        for (int j = 0; j <= n; j++)
        {
            if (dp[j] == INF)
                continue;

            if (type == '1')
            {
                if (j + 1 <= n)
                {
                    next_dp[j + 1] = min(next_dp[j + 1], max(0LL, dp[j] - d));
                }
            }
            else
            {
                if (dp[j] < x)
                {
                    if (j + 1 <= n)
                    {
                        next_dp[j + 1] = min(next_dp[j + 1], max(0LL, dp[j] - d));
                    }
                }
                next_dp[j] = min(next_dp[j], dp[j]);
            }
        }
        dp = next_dp;
    }

    int ans = 0;
    for (int j = n; j >= 0; j--)
    {
        if (dp[j] != INF)
        {
            ans = j;
            break;
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}