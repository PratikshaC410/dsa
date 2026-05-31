#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    map<int, int> freq;
    int max_freq = 0;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        freq[val]++;
        max_freq = max(max_freq, freq[val]);
    }

    // The beautiful optimal solution
    cout << min(n / 2, n - max_freq) << "\n";
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