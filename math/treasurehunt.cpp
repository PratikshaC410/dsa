#include <iostream>

using namespace std;

void solve()
{
    long long x, y, a;
    cin >> x >> y >> a;

    long long target = a + 1;
    long long cycle_depth = x + y;

    long long full_cycles = (target - 1) / cycle_depth;

    long long remaining_depth = target - (full_cycles * cycle_depth);

    if (remaining_depth <= x)
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