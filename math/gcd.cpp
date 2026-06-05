#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const vector<long long> PRIMES = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
    73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151,
    157, 163, 167, 173, 179, 181, 191, 193, 197, 199};

void solve()
{
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    for (long long p : PRIMES)
    {
        bool found_coprime = false;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] % p != 0)
            {
                found_coprime = true;
                break;
            }
        }
        if (found_coprime)
        {
            cout << p << " its a prime\n";
            return;
        }
    }

    cout << -1 << "\n";
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