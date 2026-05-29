#include <iostream>
#include <vector>
#include <set>

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

    int target_strength = a[j - 1];

    // Collect all distinct strengths strictly greater than player j's strength
    set<int> distinct_stronger;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > target_strength)
        {
            distinct_stronger.insert(a[i]);
        }
    }

    // U is the number of unique strictly greater strengths
    int U = distinct_stronger.size();

    // Player j needs U + 1 spots to be guaranteed a place among the survivors
    if (U + 1 <= k)
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