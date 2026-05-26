#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    int p;
    cin >> p;
    int left_ops = 0;
    for (int i = p - 1; i >= 1; --i)
    {
        if (a[i] != a[i + 1])
        {
            left_ops++;
        }
    }

    int right_ops = 0;
    for (int i = p + 1; i <= n; ++i)
    {
        if (a[i] != a[i - 1])
        {
            right_ops++;
        }
    }

    cout << max(left_ops, right_ops) << "\n";
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