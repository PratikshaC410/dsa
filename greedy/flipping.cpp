#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        vector<int> ans;
        int flip = 0;

        for (int i = n; i >= 1; i--)
        {
            ll cur = (flip ? -a[i] : a[i]);

            if (cur > 0)
            {
                ans.push_back(i);
                flip ^= 1;
            }
        }

        reverse(ans.begin(), ans.end());

        cout << ans.size() << "\n";
        for (int x : ans)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}