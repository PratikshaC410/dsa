#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    vector<long long> ans(n, 0);

    for (int l = 0; l < n; l++)
    {
        vector<long long> w_cw(n, 0);
        vector<long long> w_ccw(n, 0);

        w_cw[l] = 0;
        for (int step = 1; step < n; step++)
        {
            int curr = (l + step) % n;
            int prev = (curr - 1 + n) % n;
            w_cw[curr] = max(w_cw[prev], h[prev]);
        }

        w_ccw[l] = 0;
        for (int step = 1; step < n; step++)
        {
            int curr = (l - step + n) % n;
            int next = (curr + 1) % n;
            w_ccw[curr] = max(w_ccw[next], h[curr]);
        }

        long long current_total_volume = 0;
        for (int i = 0; i < n; i++)
        {
            current_total_volume += min(w_cw[i], w_ccw[i]);
        }
        ans[l] = current_total_volume;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}