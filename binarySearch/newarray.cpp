#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    // Pre-sort elements along with their original index to keep a global sorted reference
    vector<pair<long long, int>> sorted_vals(n);
    for (int i = 0; i < n; ++i)
    {
        sorted_vals[i] = {a[i], i};
    }
    sort(sorted_vals.begin(), sorted_vals.end());

    vector<int> ans(n, 0);

    for (int i = 0; i < n; ++i)
    {
        long long val_i = a[i];

        // Extract elements that appear strictly after index i
        // Because sorted_vals is sorted, valid_j will be inherently sorted by value
        vector<long long> valid_j;
        valid_j.reserve(n - i);

        for (const auto &p : sorted_vals)
        {
            if (p.second > i)
            {
                valid_j.push_back(p.first);
            }
        }

        if (valid_j.empty())
        {
            ans[i] = 0;
            continue;
        }

        int max_valid = 0;

        // Test placing k at every unique a[j] data point to find the maximum capture window
        for (int idx = 0; idx < valid_j.size(); ++idx)
        {
            // Optimization: Skip duplicates of the same candidate value for k
            if (idx > 0 && valid_j[idx] == valid_j[idx - 1])
            {
                continue;
            }

            long long k = valid_j[idx];
            long long target_dist = abs(val_i - k);

            // Calculate strict boundary limits
            long long low_val = k - target_dist;
            long long high_val = k + target_dist;

            // Binary search for the continuous range of values falling strictly within the window
            auto left_it = upper_bound(valid_j.begin(), valid_j.end(), low_val);
            auto right_it = lower_bound(valid_j.begin(), valid_j.end(), high_val);

            int current_valid = distance(left_it, right_it);
            max_valid = max(max_valid, current_valid);
        }

        ans[i] = max_valid;
    }

    // Print the final answer sequence
    for (int i = 0; i < n; ++i)
    {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main()
{
    // Optimize standard I/O operations for competitive programming execution speed
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