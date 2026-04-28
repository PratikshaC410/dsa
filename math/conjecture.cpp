#include <iostream>
#include <cmath>

using namespace std;

void solve()
{
    long long k, x;
    cin >> k >> x;
    long long initial_value = x;

    for (int i = 0; i < k; ++i)
    {
        initial_value *= 2;
    }

    cout << initial_value << endl;
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