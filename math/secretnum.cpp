#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    if (!(cin >> n))
        return;

    set<ll> results;
    ll p10 = 10;

    while (p10 < n)
    {
        ll divisor = p10 + 1;

        if (n % divisor == 0)
        {
            results.insert(n / divisor);
        }

        if (p10 > 2e17)
            break;
        p10 *= 10;
    }

    if (results.empty())
    {
        cout << 0 << endl;
    }
    else
    {
        cout << results.size();
        for (ll x : results)
        {
            cout << " " << x;
        }
        cout << endl;
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