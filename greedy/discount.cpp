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

        sort(a.begin(), a.end(), greater<long long>());

        sort(b.begin(), b.end(), greater<int>());

        long long total_cost = 0;
        int product_idx = 0;

        // Apply each voucher
        for (int i = 0; i < k && product_idx < n; i++)
        {
            int voucher_value = b[i];

            if (product_idx + voucher_value <= n)
            {
                for (int j = 0; j < voucher_value - 1; j++)
                {
                    total_cost += a[product_idx + j];
                }
                product_idx += voucher_value;
            }
            else
            {
                while (product_idx < n)
                {
                    total_cost += a[product_idx];
                    product_idx++;
                }
                break;
            }
        }

        // Add remaining products at full price
        while (product_idx < n)
        {
            total_cost += a[product_idx];
            product_idx++;
        }

        cout << total_cost << "\n";
    }

    return 0;
}