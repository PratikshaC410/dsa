#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    // 1. Maximize: Fill all 101 -> 111
    bool changed = true;
    while (changed)
    {
        changed = false;
        for (int i = 1; i < n - 1; i++)
        {
            if (s[i] == '0' && s[i - 1] == '1' && s[i + 1] == '1')
            {
                s[i] = '1';
                changed = true;
            }
        }
    }

    // Calculate Max
    int max_ones = 0;
    for (char c : s)
        if (c == '1')
            max_ones++;

    // 2. Minimize: From the maximized string, reduce blocks
    int min_ones = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            int j = i;
            while (j < n && s[j] == '1')
                j++;

            int L = j - i;
            // The formula: You can remove (L-1)/2 ones from a block of length L
            min_ones += (L - (L - 1) / 2);

            i = j - 1; // Move iterator to end of block
        }
    }

    cout << min_ones << " " << max_ones << endl;
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