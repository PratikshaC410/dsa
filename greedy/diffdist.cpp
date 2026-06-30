#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    //  1, 2, ..., n
    for (int i = 1; i <= n; ++i)
    {
        cout << i << " ";
    }

    // 2, 3, ..., n, 1
    for (int i = 2; i <= n; ++i)
    {
        cout << i << " ";
    }
    cout << 1 << " ";

    //  1, 2, ..., n
    for (int i = 1; i <= n; ++i)
    {
        cout << i << " ";
    }

    //  1, 2, ..., n
    for (int i = 1; i <= n; ++i)
    {
        cout << i << " ";
    }

    cout << "\n";
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
