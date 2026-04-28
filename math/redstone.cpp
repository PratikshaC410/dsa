#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    map<int, int> counts;
    bool possible = false;

    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        counts[a]++;
        if (counts[a] >= 2)
        {
            possible = true;
        }
    }

    if (possible)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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