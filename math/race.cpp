#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void solve()
{
    int a, x, y;
    cin >> a >> x >> y;

    bool possible = false;

    for (int p = -200; p <= 200; ++p)
    {
        if (p == a)
            continue;

        if (abs(p - x) < abs(a - x) && abs(p - y) < abs(a - y))
        {
            possible = true;
            break;
        }
    }

    if (possible)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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