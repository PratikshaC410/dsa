#include <iostream>
#include <string>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    // Construct a string with k '1's followed by (n - k) '0's
    string s = string(k, '1') + string(n - k, '0');

    cout << s << "\n";
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