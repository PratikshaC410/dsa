#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    long long total_sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        total_sum += a[i];
    }

    vector<long long> b = a;
    sort(b.begin(), b.end());

    long long initial_stays = 0;
    for (int i = 0; i < n; i++)
    {
        initial_stays += min(a[i], b[i]);
    }

    long long max_moves = total_sum - initial_stays;

    cout << max_moves << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}