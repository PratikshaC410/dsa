#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long m;
        cin >> n >> m;

        vector<long long> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
        }

        long long runs = 0;
        long long prev_time = 0;
        bool ok = true;

        for (int i = 0; i < n; i++)
        {
            long long gap = a[i] - prev_time;
            int cur_side = runs % 2;

            if (gap < abs(cur_side - b[i]))
            {
                ok = false;
                break;
            }

            int need = (b[i] - cur_side + 2) % 2;

            if (gap % 2 == need)
            {
                runs += gap;
            }
            else
            {
                runs += gap - 1;
            }

            prev_time = a[i];
        }

        if (!ok)
        {
            cout << -1 << '\n';
            continue;
        }

        // remaining time
        runs += (m - prev_time);

        cout << runs << '\n';
    }

    return 0;
}