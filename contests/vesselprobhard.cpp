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
        cin >> h[i];

    int g = 0;
    for (int i = 1; i < n; i++)
        if (h[i] > h[g])
            g = i;

    vector<long long> b(n);
    for (int i = 0; i < n; i++)
        b[i] = h[(g + 1 + i) % n];

    vector<long long> rp(n, 0), lp(n, 0);

    {
        struct Entry
        {
            long long val;
            long long cnt;
            long long sum;
        };
        vector<Entry> stk;
        long long total = 0;
        for (int l = n - 2; l >= 0; l--)
        {
            long long nc = 1, ns = b[l];
            while (!stk.empty() && stk.back().val <= b[l])
            {
                auto &top = stk.back();
                total -= top.sum;
                ns += b[l] * top.cnt;
                nc += top.cnt;
                stk.pop_back();
            }
            stk.push_back({b[l], nc, ns});
            total += ns;
            rp[l] = total;
        }
    }

    {
        struct Entry
        {
            long long val;
            long long cnt;
            long long sum;
        };
        vector<Entry> stk;
        long long total = 0;
        stk.push_back({b[n - 1], 0, 0});

        for (int l = 1; l < n; l++)
        {
            long long nc = 1, ns = b[l - 1];
            while (!stk.empty() && stk.back().val <= b[l - 1])
            {
                auto &top = stk.back();
                total -= top.sum;
                ns += b[l - 1] * top.cnt;
                nc += top.cnt;
                stk.pop_back();
            }
            stk.push_back({b[l - 1], nc, ns});
            total += ns;
            lp[l] = total;
        }
    }

    vector<long long> ans(n);
    for (int l = 0; l < n; l++)
    {
        int orig = (g + 1 + l) % n;
        ans[orig] = lp[l] + rp[l];
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n - 1];
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}