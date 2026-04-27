#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    bool has_even = false;
    bool has_odd = false;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] % 2 == 0)
            has_even = true;
        else
            has_odd = true;
    }

    // If both parities exist, the entire array can be sorted
    // lexicographically because different parities act as swap bridges.
    if (has_even && has_odd)
    {
        sort(a.begin(), a.end());
    }

    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
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