#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    ll surplus = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            surplus += (a[i] - b[i]);
        }
    }

    // The total iterations is the surplus plus the 1 iteration
    // where it realizes it can no longer decrease anything.
    cout << surplus + 1 << endl;
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