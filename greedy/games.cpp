#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> h(n);
    int max_h = 0;
    int min_h = 7;

    for (int i = 0; i < n; ++i)
    {
        cin >> h[i];
        if (h[i] > max_h)
            max_h = h[i];
        if (h[i] < min_h)
            min_h = h[i];
    }

    int ans = max_h + 1 - min_h;
    cout << ans << "\n";
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}