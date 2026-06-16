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

        bool has_marked[2] = {false, false};

        for (int i = 0; i < m; i++)
        {
            int p = x[i] & 1;
            if (!pq[p].empty())
            {
                if (!has_marked[p] || pq[p].top() > 0)
                {
                    marked += pq[p].top();
                    pq[p].pop();
                    has_marked[p] = true;
                }
            }
        }

        cout << total - marked << "\n";
    }
    return 0;
}