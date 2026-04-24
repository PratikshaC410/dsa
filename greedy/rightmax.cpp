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

    int operations = 0;
    int current_max = -1;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        if (val >= current_max)
        { // Must be >= to catch the rightmost maximums
            current_max = val;
            operations++;
        }
    }

    cout << operations << endl;
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