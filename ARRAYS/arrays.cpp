#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            cout << 0 << "\n";
            continue;
        }

        vector<long long> midpoints;
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] != a[j])
            {
                midpoints.push_back(a[i] + a[j]);
            }
        }

        set<long long> candidates;
        candidates.insert(-4000000000LL);
        candidates.insert(4000000000LL);
        for (long long m : midpoints)
        {
            candidates.insert(m - 1);
            candidates.insert(m + 1);
        }

        int max_count = 0;
        for (long long k2 : candidates)
        {
            int current = 0;
            for (int j = i + 1; j < n; j++)
            {

                if (abs(2 * a[i] - k2) > abs(2 * a[j] - k2))
                {
                    current++;
                }
            }
            max_count = max(max_count, current);
        }
        cout << max_count << (i == n - 1 ? "" : " ");
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}