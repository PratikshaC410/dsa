#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> a(m);
        for (int i = 0; i < m; i++)
            cin >> a[i];

        bool ok = true;
        for (int i = 0; i < m - 1; i++)
        {
            if (!(a[i + 1] == a[i] + 1 || a[i + 1] == 1))
            {
                ok = false;
                break;
            }
        }

        if (!ok)
        {
            cout << 0 << '\n';
            continue;
        }

        vector<int> seg;
        int len = 1;
        for (int i = 1; i < m; i++)
        {
            if (a[i] == 1)
            {
                seg.push_back(len);
                len = 1;
            }
            else
            {
                len++;
            }
        }
        seg.push_back(len);

        int L = 0;
        for (int i = 0; i < (int)seg.size(); i++)
        {
            L = max(L, seg[i] - i);
        }

        L = max(L, a[0]);

        int R = n - ((int)seg.size() - 1);

        int ans = max(0, R - L + 1);
        cout << ans << '\n';
    }

    return 0;
}