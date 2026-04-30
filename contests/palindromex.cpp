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
    int max_mex = 1;

    int L = pos[0][0], R = pos[0][1];

    for (int i = 1; i < n; i++)
    {
        if ((pos[i][0] > L && pos[i][0] < R) || (pos[i][1] > L && pos[i][1] < R))
        {
            max_mex = max(max_mex, 2);
        }
    }
    int current_k = 1;
    while (current_k < n)
    {
        int p1 = pos[current_k][0], p2 = pos[current_k][1];
        if (p1 < L && p2 > R && (L - p1 == p2 - R))
        {
            L = p1;
            R = p2;
            current_k++;
            max_mex = max(max_mex, current_k);
        }
        else
        {
            break;
        }
    }

    if (current_k < n)
    {
        if ((pos[current_k][0] > L && pos[current_k][0] < R) ||
            (pos[current_k][1] > L && pos[current_k][1] < R))
        {
            max_mex = max(max_mex, current_k + 1);
        }
    }

    cout << max_mex << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}