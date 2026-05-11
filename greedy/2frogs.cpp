#include <iostream>
#include <cmath>

using namespace std;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;

    int distance = abs(a - b);

    // If the distance is even, Alice can guarantee a win.
    if (distance % 2 == 0)
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