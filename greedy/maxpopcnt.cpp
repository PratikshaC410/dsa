#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int ans = 0;
        int cost = 1;

        while (cost <= n)
        {
            int take = min(k, n / cost);

            ans += take;
            n -= take * cost;

            cost <<= 1;
        }

        cout << ans << "\n";
    }

    return 0;
}