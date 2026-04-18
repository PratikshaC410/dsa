#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    if (!(cin >> n))
        return;

    vector<long long> g(n);
    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
    }

    // Sort descending to ensure we pair the largest values together
    sort(g.begin(), g.end(), greater<long long>());

    long long min_emeralds = 0;

    // The cost is the sum of the first, third, fifth, etc., largest grumpiness values
    for (int i = 0; i < n; i += 2)
    {
        min_emeralds += g[i];
    }

    cout << min_emeralds << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        solve();
    }
    return 0;
}