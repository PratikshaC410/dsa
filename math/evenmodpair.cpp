#include <iostream>
#include <vector>
#include <algorithm>

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

    int limit = min(n, 4);

    for (int i = 0; i < limit; i++)
    {
        for (int j = i + 1; j < limit; j++)
        {
            if ((a[j] % a[i]) % 2 == 0)
            {
                cout << a[i] << " " << a[j] << "\n";
                return;
            }
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