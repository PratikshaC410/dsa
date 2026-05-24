#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<int> b(k);
        for (int i = 0; i < k; i++)
        {
            cin >> b[i];
        }

        // Sort products in ASCENDING order (cheapest first)
        sort(a.begin(), a.end());

        // Sort vouchers in DESCENDING order (largest first)
        sort(b.begin(), b.end(), greater<int>());

        long long total_cost = 0;
        int idx = 0;

        // Apply each voucher
        for (int i = 0; i < k && idx < n; i++)
        {
            int voucher_size = b[i];

            if (idx + voucher_size <= n)
            {
                // Skip the cheapest product (index idx), pay for rest
                idx++; // skip cheapest
                for (int j = 0; j < voucher_size - 1; j++)
                {
                    total_cost += a[idx];
                    idx++;
                }
            }
            else
            {
                // Can't use this voucher, move to next
                continue;
            }
        }

        // Pay for remaining products
        while (idx < n)
        {
            total_cost += a[idx];
            idx++;
        }

        cout << total_cost << "\n";
    }

    return 0;
}