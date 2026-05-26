#include <iostream>
#include <algorithm>

using namespace std;

void solve()
{
    long long a, b, n;
    cin >> a >> b >> n;

    long long M = a / b;

    if (n <= M)
    {
        cout << n << "\n";
    }
    else
    {
        cout << 1 + M << "\n";
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