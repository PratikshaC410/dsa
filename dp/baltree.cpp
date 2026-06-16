#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    vector<long long> odd_pool, even_pool;
    long long total_sum = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        total_sum += a[i];
        // 1-based indexing parity check
        if ((i + 1) % 2 != 0)
        {
            odd_pool.push_back(a[i]);
        }
        else
        {
            even_pool.push_back(a[i]);
        }
    }

    int c_odd = 0, c_even = 0;
    for (int i = 0; i < m; ++i)
    {
        int x;
        cin >> x;
        if (x % 2 != 0)
        {
            c_odd++;
        }
        else
        {
            c_even++;
        }
    }

    // Sort both pools in descending order to easily pick the largest elements
    sort(odd_pool.rbegin(), odd_pool.rend());
    sort(even_pool.rbegin(), even_pool.rend());

    // Determine how many elements we can grab from each pool
    int take_odd = min((int)odd_pool.size(), c_odd);
    int take_even = min((int)even_pool.size(), c_even);

    long long max_marked_sum = 0;

    // Summing the best elements from the odd pool (Fixed loop index bug)
    for (int i = 0; i < take_odd; ++i)
    {
        max_marked_sum += odd_pool[i];
    }

    // Summing the best elements from the even pool
    for (int i = 0; i < take_even; ++i)
    {
        max_marked_sum += even_pool[i];
    }

    // Unmarked sum = Total sum - Max possible marked sum
    long long min_unmarked_sum = total_sum - max_marked_sum;
    cout << min_unmarked_sum << "\n";
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