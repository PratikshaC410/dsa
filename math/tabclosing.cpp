#include <iostream>
#include <algorithm>

using namespace std;

void solve()
{
    long long a, b, n;
    cin >> a >> b >> n;

    if (n == 1)
    {
        cout << 1 << "\n";
        return;
    }

    if (min(b, a / n) == min(b, a / 1))
    {
        cout << 1 << "\n";
    }
    else
    {
        cout << 2 << "\n";
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
