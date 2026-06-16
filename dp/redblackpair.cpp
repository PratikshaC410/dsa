#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    // dp[i] stores the min repaints for the first i columns (1-indexed)
    vector<int> dp(n + 1, 0);

    // Base case for 1st column
    dp[1] = (s1[0] == s2[0] ? 0 : 1);

    for (int i = 2; i <= n; ++i)
    {
        // Choice 1: Vertical domino at column i
        int cost_vertical = (s1[i - 1] == s2[i - 1] ? 0 : 1);
        int option1 = dp[i - 1] + cost_vertical;

        // Choice 2: Two horizontal dominoes at columns i-1 and i
        int cost_horizontal_top = (s1[i - 2] == s1[i - 1] ? 0 : 1);
        int cost_horizontal_bot = (s2[i - 2] == s2[i - 1] ? 0 : 1);
        int option2 = dp[i - 2] + cost_horizontal_top + cost_horizontal_bot;

        // Take the minimum of both structural choices
        dp[i] = min(option1, option2);
    }

    cout << dp[n] << "\n";
}

int main()
{
    // Optimize standard I/O operations for performance
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