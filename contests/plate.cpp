#include <iostream>

using namespace std;

void solve()
{
    int x, y;
    if (!(cin >> x >> y))
        return;

    // Check if both coordinates are odd
    if (x % 2 != 0 && y % 2 != 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
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