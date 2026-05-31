#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int min_calls = n;

    for (int i = 0; i < n; i++)
    {
        // L: count of elements strictly less than a[i]
        int L = lower_bound(a.begin(), a.end(), a[i]) - a.begin();

        // R: count of elements strictly greater than a[i]
        int R = a.end() - upper_bound(a.begin(), a.end(), a[i]);

        int current_calls = max(L, R);
        min_calls = min(min_calls, current_calls);
    }

    cout << min_calls << "\n";
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