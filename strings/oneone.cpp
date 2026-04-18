#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;

        // Maximum: fill all gaps between 1's
        string maxStr = s;
        bool changed = true;
        while (changed)
        {
            changed = false;
            for (int i = 1; i < n - 1; i++)
            {
                if (maxStr[i - 1] == '1' && maxStr[i + 1] == '1' && maxStr[i] == '0')
                {
                    maxStr[i] = '1';
                    changed = true;
                }
            }
        }

        // Minimum: count 1's that have at least one neighbor that is NOT 1
        // These cannot be changed
        int minOnes = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                bool canChange = (i > 0 && s[i - 1] == '1') && (i < n - 1 && s[i + 1] == '1');
                if (!canChange)
                {
                    minOnes++;
                }
            }
        }

        // Also need to account for the structure - consecutive 1's separated by 0's
        minOnes = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                bool leftIs1 = (i > 0 && s[i - 1] == '1');
                bool rightIs1 = (i < n - 1 && s[i + 1] == '1');
                if (!leftIs1 || !rightIs1)
                {
                    minOnes++;
                }
            }
        }

        int maxOnes = count(maxStr.begin(), maxStr.end(), '1');

        cout << minOnes << " " << maxOnes << "\n";
    }

    return 0;
}