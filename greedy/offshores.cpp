#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    long long x, y;
    cin >> n >> x >> y;

    vector<long long> a(n);
    long long total_contributed_y = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        total_contributed_y += (a[i] / x) * y;
    }

    long long max_rubles = 0;
    for (int i = 0; i < n; i++)
    {
        long long current_total = a[i] + (total_contributed_y - (a[i] / x) * y);
        max_rubles = max(max_rubles, current_total);
    }

    cout << max_rubles << "\n";
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