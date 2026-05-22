#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
vector<int> used;
int n;

bool backtrack(int pos)
{
    // Skip filled positions
    while (pos < 2 * n && ans[pos] != 0)
        pos++;

    // All positions filled
    if (pos == 2 * n)
        return true;

    // Try larger numbers first
    for (int num = n; num >= 1; num--)
    {
        if (used[num])
            continue;

        // Try placing second occurrence at valid positions
        for (int j = pos + num; j < 2 * n; j += num)
        {
            if (ans[j] != 0)
                continue;

            ans[pos] = ans[j] = num;
            used[num] = 1;

            if (backtrack(pos + 1))
                return true;

            ans[pos] = ans[j] = 0;
            used[num] = 0;
        }
    }

    return false;
}

void solve()
{
    cin >> n;

    ans.assign(2 * n, 0);
    used.assign(n + 1, 0);

    backtrack(0);

    for (int i = 0; i < 2 * n; i++)
    {
        if (i)
            cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}