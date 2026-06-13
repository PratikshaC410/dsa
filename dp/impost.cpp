#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void solve()
{
    string r;
    cin >> r;
    int n = r.length();

    int dp_s = (r[0] == 'u' ? 1 : 0);
    int dp_u = INF;

    for (int i = 1; i < n; ++i)
    {
        int next_dp_s = INF;
        int next_dp_u = INF;

        int cost_s = (r[i] == 'u' ? 1 : 0);
        next_dp_s = cost_s + min(dp_s, dp_u);

        if (r[i] == 'u')
        {
            next_dp_u = dp_s;
        }

        dp_s = next_dp_s;
        dp_u = next_dp_u;
    }

    cout << dp_s << " dp_s will be \n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }
    return 0;
}