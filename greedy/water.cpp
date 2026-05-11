#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> min_val;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int val;
            cin >> val;
            int diag_id = i - j;

            if (min_val.find(diag_id) == min_val.end())
            {
                min_val[diag_id] = val;
            }
            else
            {
                min_val[diag_id] = min(min_val[diag_id], val);
            }
        }
    }

    long long total_magic = 0;
    for (auto const &[id, lowest] : min_val)
    {
        if (lowest < 0)
        {
            total_magic += abs(lowest);
        }
    }

    cout << total_magic << endl;
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