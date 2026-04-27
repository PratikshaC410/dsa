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

    // 1. Determine how many zeros should be in the string
    int zero_count = 0;
    for (char c : s)
    {
        if (c == '0')
            zero_count++;
    }

    // 2. In a sorted string, all '0's occupy the first 'zero_count' positions.
    // Count how many '1's are currently in that "0-zone".
    // Each '1' in the 0-zone must be swapped with a '0' in the 1-zone.
    int misplaced_ones_in_zero_zone = 0;
    for (int i = 0; i < zero_count; i++)
    {
        if (s[i] == '1')
        {
            misplaced_ones_in_zero_zone++;
        }
    }

    // The number of operations is exactly equal to the number of
    // misplaced pairs (one '1' in the 0-zone and one '0' in the 1-zone).
    cout << misplaced_ones_in_zero_zone << endl;
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