#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve()
{
    int n, x, s;
    cin >> n >> x >> s;
    string u;
    cin >> u;
    vector<int> dp(x + 1, -1);
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        vector<int> next_dp = dp;
        char personality = u[i];

        for (int j = 0; j <= x; j++)
        {
            if (dp[j] == -1)
                continue;

            int seated = dp[j];
            int available_seats = (j * s) - seated;

            if ((personality == 'I' || personality == 'A') && j < x)
            {
                next_dp[j + 1] = max(next_dp[j + 1], seated + 1);
            }

            if ((personality == 'E' || personality == 'A') && available_seats > 0)
            {
                next_dp[j] = max(next_dp[j], seated + 1);
            }
        }
        dp = move(next_dp);
    }

    int max_seated = 0;
    for (int j = 0; j <= x; j++)
    {
        max_seated = max(max_seated, dp[j]);
    }

    cout << max_seated << "\n";
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