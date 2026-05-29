#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    // Count remainders modulo 4 for numbers from 0 to n-1
    int c0 = 0, c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < n; ++i)
    {
        int rem = i % 4;
        if (rem == 0)
            c0++;
        else if (rem == 1)
            c1++;
        else if (rem == 2)
            c2++;
        else if (rem == 3)
            c3++;
    }

    // Bob wins if and only if paired buckets have perfectly equal sizes
    if (c0 == c3 && c1 == c2)
    {
        cout << "Bob\n";
    }
    else
    {
        cout << "Alice\n";
    }
}

int main()
{
    // Fast I/O
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