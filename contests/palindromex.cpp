#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> pos(n);
    for (int i = 0; i < 2 * n; i++)
    {
        int x;
        cin >> x;
        pos[x].push_back(i);
    }

    int ans = 1;

    int L = pos[0][0], R = pos[0][1];

    for (int i = 1; i < n; i++)
    {
        if (pos[i][0] > L && pos[i][0] < R)
            ans = max(ans, 2);
        if (pos[i][1] > L && pos[i][1] < R)
            ans = max(ans, 2);
    }

    int current_L = L, current_R = R;
    int k = 1;
    while (k < n)
    {
        int p1 = pos[k][0], p2 = pos[k][1];

        if (p1 < current_L && p2 > current_R)
        {
            if (current_L - p1 == p2 - current_R)
            {
                current_L = p1;
                current_R = p2;
                k++;

                ans = max(ans, k);
            }
            else
                break;
        }
        else
            break;
    }

    if (k < n)
    {
        if ((pos[k][0] > current_L && pos[k][0] < current_R) ||
            (pos[k][1] > current_L && pos[k][1] < current_R))
        {
            ans = max(ans, k + 1);
        }
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}