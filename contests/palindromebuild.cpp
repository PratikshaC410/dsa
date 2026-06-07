#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll buildPalin(ll half, int h, int L)
{
    string sh = to_string(half);
    if ((int)sh.size() != h)
        return -1;
    string rev(sh.rbegin(), sh.rend());
    bool odd = L & 1;
    string full = odd ? sh + rev.substr(1) : sh + rev;
    if ((int)full.size() != L)
        return -1;
    if ((int)full.size() > 18)
        return -1;
    return stoll(full);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll ans_a = -1, ans_b = -1;

        auto tryA = [&](ll a)
        {
            if (a < 0 || a > n)
                return;
            ll b = n - a;
            if (b % 12 == 0 && (ans_a == -1 || a > ans_a))
                ans_a = a, ans_b = b;
        };

        for (ll a = 0; a <= min(9LL, n); a++)
            tryA(a);

        string ns = to_string(n);
        int maxLen = (int)ns.size();

        for (int L = 2; L <= maxLen; L++)
        {
            int h = (L + 1) / 2;
            ll half_min = 1;
            for (int i = 0; i < h - 1; i++)
                half_min *= 10;

            ll start = (L == maxLen) ? stoll(ns.substr(0, h))
                                     : half_min * 10 - 1;

            for (ll half = start;
                 half >= half_min && half > start - 14;
                 half--)
            {
                ll pal = buildPalin(half, h, L);
                if (pal != -1 && pal <= n)
                    tryA(pal);
            }
        }

        if (ans_a == -1)
            cout << "-1\n";
        else
            cout << ans_a << " " << ans_b << "\n";
    }
    return 0;
}