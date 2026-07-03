#include <bits/stdc++.h>
using namespace std;

#define int long long

int main()
{

    int t;
    cin >> t;

    long long ans = 0;
    long long cost = 1;

    while (cost <= n)
    {
        long long take = min(1LL * k, n / cost);

        ans += take;
        n -= take * cost;

        cost <<= 1;
    }

    cout << ans << '\n';

    return 0;
}