#include <iostream>
#include <string>
#include <vector>

using namespace std;
#include <iostream>
#include <string>
#include <stack>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();

    // Check if the string is just one deep nest: ((...))
    // We can check this by seeing if the sequence remains "open"
    // until the very last character.
    int balance = 0;
    bool depth_greater_than_one = false;
    bool is_simple_nest = true;

    for (int i = 0; i < n - 1; ++i)
    {
        if (s[i] == '(')
            balance++;
        else
            balance--;

        // If balance hits 0 before the end, it's not a single simple nest (like ()())
        if (balance == 0)
        {
            is_simple_nest = false;
        }
    }

    if (is_simple_nest)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
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
