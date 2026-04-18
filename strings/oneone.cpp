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

    // Phase 1: Bridge all possible gaps.
    // If we have 101, we can turn it into 111.
    // This allows us to reach the "Maximum" state.
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

    // The string 's' is now in its "Maximum" possible configuration.
    int max_ones = 0;
    for (char c : s)
        if (c == '1')
            max_ones++;

    // Phase 2: For the Minimum, we take that maximum configuration
    // and turn every '111' into '101' greedily.
    // This is equivalent to picking every other 1 in a contiguous block.
    int min_ones = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            min_ones++;
            // If we keep this 1, and the next one is also a 1,
            // we can potentially turn the NEXT one into a 0
            // IF it has a 1 after it.
            // A simpler way: in a block of length L, min 1s = (L+1)/2
            int j = i;
            while (j < n && s[j] == '1')
                j++;

            int block_len = j - i;
            if (block_len > 1)
            {
                // Correct for the range: (length + 1) / 2
                // We subtract the 1 we already added and add the formula
                min_ones--;
                min_ones += (block_len + 1) / 2;
            }
            i = j; // Skip to the end of this block
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