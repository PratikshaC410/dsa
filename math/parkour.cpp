#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        long long x, y;
        cin >> x >> y;
        if ((x - 2 * y) % 3 != 0)
        {
            cout << "NO\n";
            continue;
        }

        long long d = (x - 2 * y) / 3;
        if (d < 0)
        {
            cout << "NO\n";
            continue;
        }

        long long min_c = max(0LL, -y);
        long long max_c = d / 2;

        if (min_c <= max_c)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}