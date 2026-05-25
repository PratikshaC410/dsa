#include <iostream>
#include <string>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int c0 = 0, c1 = 0;
    for (char c : s)
    {
        if (c == '0')
            c0++;
        else
            c1++;
    }

    int needed_bad_pairs = (n / 2) - k;

    int rem0 = c0 - needed_bad_pairs;
    int rem1 = c1 - needed_bad_pairs;

    // Remaining counts must be non-negative and EVEN
    if (rem0 >= 0 && rem1 >= 0 && rem0 % 2 == 0 && rem1 % 2 == 0)
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
