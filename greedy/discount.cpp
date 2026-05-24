#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    long long total_sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        total_sum += a[i];
    }
    vector<int> b(k);
    for (int i = 0; i < k; ++i)
    {
        cin >> b[i];
    }

    // Sort products in descending order
    sort(a.begin(), a.end(), greater<long long>());
    // Sort vouchers in descending order
    sort(b.begin(), b.end(), greater<int>());

    // dp[i] will store the maximum discount obtainable using a subset of items up to index i
    // To solve efficiently, we can use a DP or a greedy approach based on the voucher choices.
    // Let's use a DP state where dp[i] = max discount using the first i products.
    vector<long long> dp(n + 1, 0);

    // To speed up voucher transitions, we notice that if we use a voucher of size x at index i,
    // the free item is a[i-1] (0-indexed), and it requires x-1 items before it.
    // So it transitions from dp[i - x] + a[i - 1].

    // We can iterate through the items, and for each item, decide whether to use the next best available voucher
    int voucher_idx = 0;

    for (int i = 1; i <= n; ++i)
    {
        // By default, the discount at i is at least the discount at i-1
        dp[i] = dp[i - 1];

        // If we can use the largest remaining voucher that fits within the prefix i
        if (voucher_idx < k && b[voucher_idx] <= i)
        {
            int x = b[voucher_idx];
            long long potential_discount = dp[i - x] + a[i - 1];
            if (potential_discount > dp[i])
            {
                dp[i] = potential_discount;
                voucher_idx++; // Consume the voucher
            }
        }
    }

    cout << total_sum - dp[n] << "\n";
}

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }
    return 0;
}