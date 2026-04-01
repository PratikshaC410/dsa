#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;

        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
        }

        int ans = __lg(n);

        if ((1LL << ans) == n)
        {
            ans--;
        }

        cout << ans << "\n";
    }

    return 0;
}