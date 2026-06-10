#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    map<int, int> frequency;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        frequency[a]++;
    }

    int max_kept = 0;

    for (auto const &[x, c] : frequency)
    {
        if (x == 0)
            continue;

        if (c >= x)
        {
            max_kept += x;
        }
    }

    cout << n - max_kept << "\n";
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