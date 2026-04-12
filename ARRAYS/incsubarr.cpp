#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    long long n, m;
    if (!(cin >> n >> m))
        return;

    vector<long long> a(static_cast<size_t>(m));
    bool has_restart = false;

    for (int i = 0; i < m; i++)
    {
        cin >> a[static_cast<size_t>(i)];
        if (i > 0)
        {
            if (a[static_cast<size_t>(i)] != a[static_cast<size_t>(i - 1)] + 1)
            {
                has_restart = true;
            }
        }
    }

    if (has_restart)
    {
        cout << 1 << endl;
    }
    else
    {
        long long result = n - a[static_cast<size_t>(m - 1)] + 1;
        cout << result << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        solve();
    }
    return 0;
}