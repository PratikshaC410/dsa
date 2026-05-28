#include <iostream>
#include <vector>
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

    vector<long long> pref_max(n);
    pref_max[0] = a[0];
    for (int i = 1; i < n; ++i)
    {
        pref_max[i] = max(pref_max[i - 1], a[i]);
    }

    long long total_cost = 0;
    long long prev_val = 1;

    total_cost += (a[0] - 1);
    prev_val = 1;

    for (int i = 1; i < n; ++i)
    {
        int pos = i + 1; // 1-based index
        if (pos % 2 == 1)
        {
            total_cost += (a[i] - 1);
            prev_val = 1;
        }
        else
        {
            long long max_available = pref_max[i];

            if (max_available > prev_val)
            {
                prev_val = max_available;
            }
            else
            {
                prev_val = max_available;
            }
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