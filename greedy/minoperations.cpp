#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int p;
    cin >> p;
    int blocks = 1;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] != a[i - 1])
        {
            blocks++;
        }
    }

    cout << blocks / 2 << "\n";
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
