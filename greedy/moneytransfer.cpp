#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    long long x, y;
    if (!(cin >> n >> x >> y))
        return;

    vector<long long> a(n);
    long long max_val = 0;
    long long total_sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        total_sum += a[i];
        if (a[i] > max_val)
        {
            max_val = a[i];
        }
    }

    long long pool = total_sum - max_val;

    long long num_transfers = pool / x;
    long long total_lost = num_transfers * (x - y);

    cout << total_sum - total_lost << endl;
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