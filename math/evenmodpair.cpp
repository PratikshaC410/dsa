#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (i + 1 < n && (a[i + 1] % a[i]) % 2 == 0)
        {
            cout << a[i] << " " << a[i + 1] << "\n";
            return;
        }
        if (i + 2 < n && (a[i + 2] % a[i]) % 2 == 0)
        {
            cout << a[i] << " " << a[i + 2] << "\n";
            return;
        }
    }

    cout << -1 << "\n";
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
