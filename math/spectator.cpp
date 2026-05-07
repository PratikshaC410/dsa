#include <iostream>

using namespace std;

void solve()
{
    long long k;
    if (!(cin >> k))
        return;

    // The spectator repeats every 3 matches
    // Match 1, 4, 7, 10... (k % 3 == 1)
    if (k % 3 == 1)
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
    // Optimize I/O for competitive programming
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