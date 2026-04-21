#include <iostream>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    // We need to find the largest power of 2 less than or equal to n.
    // Let that be 2^p. The answer is (2^p) - 1.

    int k = 1;
    // Keep shifting left until the next power of 2 exceeds n
    while ((k << 1) <= n)
    {
        k <<= 1;
    }

    // The answer is the power of 2 minus 1
    cout << k - 1 << "\n";
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