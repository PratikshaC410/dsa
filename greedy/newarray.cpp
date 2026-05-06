#include <iostream>
#include <cmath>

using namespace std;

void solve()
{
    int n, k, p;
    cin >> n >> k >> p;

    int target = abs(k);

    if (target > n * p)
    {
        cout << -1 << endl;
    }
    else
    {
        int ops = (target + p - 1) / p;
        cout << ops << endl;
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