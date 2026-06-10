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

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    long long total_max_sum = 0;
    long long max_of_mins = 0;

    for (int i = 0; i < n; i++)
    {
        total_max_sum += max(a[i], b[i]);
        max_of_mins = max(max_of_mins, min(a[i], b[i]));
    }

    long long ans = total_max_sum + max_of_mins;
    cout << ans << "\n";
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