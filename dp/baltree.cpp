#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<long long> a(n + 1);
        long long total = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            total += a[i];
        }

        vector<int> x(m);
        for (int i = 0; i < m; i++)
            cin >> x[i];
        priority_queue<long long> pq[2];
        for (int i = 1; i <= n; i++)
            pq[i & 1].push(a[i]);
        long long marked = 0;

        int need[2] = {0, 0};

        while (!pq[0].empty())
            pq[0].pop();
        while (!pq[1].empty())
            pq[1].pop();
        for (int i = 1; i <= n; i++)
            pq[i & 1].push(a[i]);

        marked = 0;
        for (int i = 0; i < m; i++)
        {
            int p = x[i] & 1;
            if (!pq[p].empty())
            {
                marked += pq[p].top();
                pq[p].pop();
            }
        }

        cout << total - marked << "\n";
    }
    return 0;
}