#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    if (!(cin >> n))
        return;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    long long x;
    cin >> x;

    if (n == 1)
    {
        cout << (a[0] == x ? "YES" : "NO") << endl;
        return;
    }

    bool possible = false;
    for (int i = 0; i < n - 1; ++i)
    {
        if (x >= min(a[i], a[i + 1]) && x <= max(a[i], a[i + 1]))
        {
            possible = true;
            break;
        }
    }

    cout << (possible ? "YES" : "NO") << endl;
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