#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int MOD = 676767677;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    map<int, int> freq;
    int max_freq = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
        max_freq = max(max_freq, freq[a[i]]);
    }

    long long total_cost = 0;

    // Process layer by layer up to the maximum frequency
    for (int i = 1; i <= max_freq; i++)
    {
        long long current_op_cost = 1;
        bool track = false;

        for (auto const &[val, count] : freq)
        {
            if (count >= i)
            {
                current_op_cost = (current_op_cost * val) % MOD;
                track = true;
            }
        }

        if (track)
        {
            total_cost = (total_cost + current_op_cost) % MOD;
        }
    }

    cout << total_cost << "\n";
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