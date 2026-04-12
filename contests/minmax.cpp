#include <iostream>
#include <algorithm>

using namespace std;

void solve()
{
    int x;
    if (!(cin >> x))
        return;

    if (x < 67)
    {
        cout << x + 1 << endl;
    }
    else
    {
        cout << 67 << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        solve();
    }
    return 0;
}