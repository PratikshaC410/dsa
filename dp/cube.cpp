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

    // dp[v] stores the min operations to end the current prefix with face v (1-indexed)
    vector<int> dp(7, 0);

    // Initialize for the first element
    for (int v = 1; v <= 6; ++v)
    {
        dp[v] = (a[0] == v) ? 0 : 1;
    }

    // Iterate through the rest of the sequence
    for (int i = 1; i < n; ++i)
    {
        vector<int> next_dp(7, 1e9);

        for (int v = 1; v <= 6; ++v)
        {
            int min_prev = 1e9;
            // Find the best valid preceding face `u`
            for (int u = 1; u <= 6; ++u)
            {
                if (u != v && u + v != 7)
                {
                    min_prev = min(min_prev, dp[u]);
                }
            }
            // Cost is min_prev + (1 if we need to change a[i] to v)
            next_dp[v] = min_prev + (a[i] == v ? 0 : 1);
        }
        dp = move(next_dp);
    }

    // The answer is the minimum operations to reach the end with any valid face
    int ans = 1e9;
    for (int v = 1; v <= 6; ++v)
    {
        ans = min(ans, dp[v]);
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