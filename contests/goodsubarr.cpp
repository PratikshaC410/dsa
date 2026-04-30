#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll total_good = 0;

    for (int l = 0; l < n; l++)
    {
        vector<ll> s;
        for (int r = l; r < n; r++)
        {
            s.push_back(a[r]);

            while (s.size() >= 3)
            {
                int m = s.size();
                if (s[m - 3] + s[m - 1] > s[m - 2])
                {
                    ll x = s[m - 3] - s[m - 2] + s[m - 1];
                    s.pop_back();
                    s.pop_back();
                    s.pop_back();
                    s.push_back(x);
                }
                else
                {
                    break;
                }
            }
            if (s.size() == 1)
            {
                total_good++;
            }
        }
    }
    cout << total_good << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}