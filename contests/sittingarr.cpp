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

    int min_j = 0;
    int max_j = 0;

    for (int i = 0; i < n; i++)
    {
        char p = u[i];

        int prev_max_j = max_j;
        if (p == 'I' && max_j < x)
        {
            max_j++;
        }
        else if (p == 'A' && max_j < x)
        {
            max_j++;
        }

        for (int j = max_j; j >= min_j; j--)
        {
            int res = dp[j];

            if (j > 0 && (p == 'I' || p == 'A'))
            {
                if (dp[j - 1] != -1)
                {
                    res = max(res, dp[j - 1] + 1);
                }
            }
            if (p == 'E' || p == 'A')
            {
                if (dp[j] != -1)
                {
                    int available_seats = (j * s) - dp[j];
                    if (available_seats > 0)
                    {
                        res = max(res, dp[j] + 1);
                    }
                }
            }

            dp[j] = res;
        }

        while (min_j <= max_j && dp[min_j] == -1)
        {
            min_j++;
        }
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