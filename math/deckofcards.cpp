#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int count0 = 0, count1 = 0, count2 = 0;
    for (char c : s)
    {
        if (c == '0')
            count0++;
        else if (c == '1')
            count1++;
        else if (c == '2')
            count2++;
    }

    int min_top = count0;
    int max_top = count0 + count2;

    int min_bot = count1;
    int max_bot = count1 + count2;

    string result = "";
    for (int i = 1; i <= n; i++)
    {
        if (i <= min_top || i > n - min_bot)
        {
            result += '-';
        }
        else if (i > max_top && i <= n - max_bot)
        {
            result += '+';
        }
        else
        {
            result += '?';
        }
    }
    cout << result << "\n";
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