#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    long long total_sum = 0;
    for (int i = 0; i < n; ++i)
    {
        long long val;
        cin >> val;
        total_sum += val;
    }

    long long ans = total_sum - (n - 1);
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