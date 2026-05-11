#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 1e9; // Large value representing infinity

void solve()
{
    int n;
    cin >> n;

    int min_10 = INF;
    int min_01 = INF;
    int min_11 = INF;

    for (int i = 0; i < n; ++i)
    {
        int m;
        string s;
        cin >> m >> s;

        if (s == "11")
        {
            min_11 = min(min_11, m);
        }
        else if (s == "10")
        {
            min_10 = min(min_10, m);
        }
        else if (s == "01")
        {
            min_01 = min(min_01, m);
        }
    }

    // Compare the cost of one "11" book vs the sum of "10" and "01" books
    int option1 = min_11;
    int option2 = (min_10 == INF || min_01 == INF) ? INF : (min_10 + min_01);

    int result = min(option1, option2);

    if (result >= INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << result << endl;
    }
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