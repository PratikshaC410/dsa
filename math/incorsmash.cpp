#include <iostream>
#include <set>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    set<int> unique_non_zeros;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        if (val > 0)
        {
            unique_non_zeros.insert(val);
        }
    }

    // If the array is already all zeros, 0 operations are needed
    if (unique_non_zeros.empty())
    {
        cout << 0 << "\n";
    }
    else
    {
        // 2 operations (Increase + Smash) per unique value, minus 1 for the last value
        cout << (2 * unique_non_zeros.size()) - 1 << "\n";
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