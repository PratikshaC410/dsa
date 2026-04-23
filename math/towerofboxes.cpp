#include <iostream>
#include <cmath>

using namespace std;

void solve()
{
    int n, m, d;
    cin >> n >> m >> d;

    int boxes_above = d / m;
    int max_per_tower = boxes_above + 1;

    // Minimum towers = ceil(n / max_per_tower)
    int ans = (n + max_per_tower - 1) / max_per_tower;

    cout << ans << endl;
}

int main()
{
    // Optimization for faster I/O
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