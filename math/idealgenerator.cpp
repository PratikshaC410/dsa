#include <iostream>

using namespace std;

void solve()
{
    int k;
    cin >> k;

    if (k % 2 != 0)
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