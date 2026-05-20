#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> counts;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        counts[a[i]]++;
    }

    if (n == 3)
    {
        if (counts.size() == 1)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
        return;
    }

    int max_freq = 0;
    for (auto const &[val, count] : counts)
    {
        max_freq = max(max_freq, count);
    }

    if (max_freq >= (n + 1) / 2)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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