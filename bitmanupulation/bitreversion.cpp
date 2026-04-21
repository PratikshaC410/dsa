#include <iostream>

using namespace std;

void solve()
{
    long long x, y, z;
    cin >> x >> y >> z;

    if ((x & y) == (y & z) && (x & z) == (y & z))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}