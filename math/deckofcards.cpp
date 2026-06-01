#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int lo_min = 1, lo_max = 1;
        int hi_min = n, hi_max = n;

        for (char c : s)
        {
            if (c == '0')
            {
                lo_min++;
                lo_max++;
            }
            else if (c == '1')
            {
                hi_min--;
                hi_max--;
            }
            else
            {
                lo_max++;
                hi_min--;
                lo_max = min(lo_max, n + 1);
                hi_min = max(hi_min, 0);
                // If only 1 card left, '2' must remove it
                if (lo_min == hi_max)
                {
                    lo_min++;
                }
            }
        }

        string ans(n, '?');

        if (lo_min > hi_max)
        {
            fill(ans.begin(), ans.end(), '-');
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                if (i >= lo_max && i <= hi_min)
                {
                    ans[i - 1] = '+';
                }
                else if (i < lo_min || i > hi_max)
                {
                    ans[i - 1] = '-';
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}