#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// Helper function to check if a string is universal
bool is_universal(const string &s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s < rev;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    if (is_universal(s))
    {
        cout << "YES\n";
        return;
    }

    if (k == 0)
    {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            swap(s[i], s[j]);
            if (is_universal(s))
            {
                cout << "YES\n";
                return;
            }
            swap(s[i], s[j]);
        }
    }

    if (k >= 2)
    {
        char min_c = *min_element(s.begin(), s.end());
        char max_c = *max_element(s.begin(), s.end());
        if (min_c < max_c)
        {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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
