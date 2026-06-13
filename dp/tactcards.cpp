#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    // dp[0] stores max value if incoming multiplier is +1
    // dp[1] stores max value if incoming multiplier is -1
    // Base case for after the last turn (index n)
    long long next_dp_pos = 0;
    long long next_dp_neg = 0;

    // Move backwards from the final turn to the first turn
    for (int i = n - 1; i >= 0; --i)
    {
        long long cur_dp_pos = max(-a[i] + next_dp_pos, b[i] + next_dp_neg);
        long long cur_dp_neg = max(a[i] + next_dp_neg, -b[i] + next_dp_pos);

        next_dp_pos = cur_dp_pos;
        next_dp_neg = cur_dp_neg;
    }

    // Since the game starts with score 0 (which has a positive sign context)
    cout << next_dp_pos << "\n";
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