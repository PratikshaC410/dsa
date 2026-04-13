#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Problem Intuition:
 * gcd(a + d, b + d) = gcd(a + d, |(a + d) - (b + d)|)
 * = gcd(a + d, |a - b|)
 * Since the GCD of any number and |a - b| cannot exceed |a - b|,
 * the maximum possible GCD is exactly |a - b|.
 * We can always find a 'd' to make (a + d) a multiple of |a - b|.
 */

void solve()
{
    int n;
    if (!(cin >> n))
        return;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long max_pleasure = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // The max pleasure for this pair is their absolute difference
            long long diff = abs(a[i] - a[j]);
            if (diff > max_pleasure)
            {
                max_pleasure = diff;
            }
        }
    }

    cout << max_pleasure << endl;
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