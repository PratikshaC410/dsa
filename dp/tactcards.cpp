#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    long long max_total_score = 0;

    for (int i = 0; i < n; ++i)
    {
        long long sign = ((n - 1 - i) % 2 == 0) ? 1 : -1;

        long long red_contribution = -sign * a[i];
        long long blue_contribution = sign * b[i];

        max_total_score += max(red_contribution, blue_contribution);
    }

    cout << max_total_score << "\n";
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