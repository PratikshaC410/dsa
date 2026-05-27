#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int first_one = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            first_one = i;
            break;
        }
    }

    int max_gap = 0;
    int current_gap = 0;

    for (int i = 0; i < n; i++)
    {
        int idx = (first_one + i) % n;

        if (s[idx] == '0')
        {
            current_gap++;
        }
        else
        {
            max_gap = max(max_gap, current_gap);
            current_gap = 0;
        }
    }
    max_gap = max(max_gap, current_gap);

    cout << max_gap << "\n";
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