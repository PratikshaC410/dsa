#include <iostream>
#include <vector>
#include <algorithm>

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

    ll total_iterations = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            total_iterations += (a[i] - b[i]);
        }
    }

    cout << total_iterations << endl;
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