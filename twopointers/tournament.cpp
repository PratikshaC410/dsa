#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n, j, k;
    cin >> n >> j >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    // Player j's strength (1-based to 0-based indexing)
    int target_strength = a[j - 1];

    // Count how many players are strictly stronger than player j
    int strictly_stronger = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > target_strength)
        {
            strictly_stronger++;
        }
    }

    // Player j can survive if the number of strictly stronger players is less than k
    if (strictly_stronger < k)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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