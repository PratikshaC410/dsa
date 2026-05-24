#include <iostream>
#include <vector>
#include <algorithm>

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

    // Step 1: Sort products in descending order
    sort(a.begin(), a.end(), greater<long long>());

    // Step 2: Sort vouchers in ascending order
    sort(b.begin(), b.end());

    long long total_discount = 0;
    int current_idx = 0;

    // Step 3: Match vouchers to elements greedily
    for (int i = 0; i < k; ++i)
    {
        int voucher_size = b[i];

        // If there aren't enough products left to satisfy the voucher size, we stop
        if (current_idx + voucher_size > n)
        {
            break;
        }

        // The cheapest item in this optimal group of 'voucher_size' elements
        // will be at index (current_idx + voucher_size - 1)
        total_discount += a[current_idx + voucher_size - 1];

        // Consume these elements
        current_idx += voucher_size;
    }

    cout << total_sum - total_discount << "\n";
}

int main()
{
    // Optimize standard I/O operations for competitive programming
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