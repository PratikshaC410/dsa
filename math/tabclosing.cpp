#include <iostream>
#include <algorithm>

using namespace std;

void solve()
{
    long long a, b, n;
    cin >> a >> b >> n;

    long long k = a / b;

    if (n <= k)
    {
        cout << n << "\n";
    }
    else
    {
        cout << 1 + k << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}