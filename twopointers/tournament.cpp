#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n, j, k;
    cin >> n >> j >> k;

    vector<int> a(n);
    int max_strength = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] > max_strength)
        {
            max_strength = a[i];
        }
    }

    // Player j is at index j - 1
    int target_strength = a[j - 1];

    if (k > 1)
    {
        cout << "YES\n";
    }
    else
    { // k == 1
        if (target_strength == max_strength)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
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