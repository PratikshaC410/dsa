#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < k; i++)
            pq.push(1);

        int ans = 0;

        while (!pq.empty() && pq.top() <= n)
        {
            int cost = pq.top();
            pq.pop();

            n -= cost;
            ans++;

            pq.push(cost * 2);
        }

        cout << ans << '\n';
    }

    return 0;
}