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

    // Player j is at index j - 1 (1-based to 0-based indexing)
    int target_strength = a[j - 1];

    int strictly_stronger = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > target_strength)
        {
            strictly_stronger++;
        }
    }

    // If the number of strictly stronger players is less than k,
    // player j can be in the top k.
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
    // Fast I/O
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