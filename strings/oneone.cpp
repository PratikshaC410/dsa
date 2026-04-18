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

        string minStr = s;
        changed = true;
        while (changed)
        {
            changed = false;
            for (int i = 1; i < n - 1; i++)
            {
                if (minStr[i - 1] == '1' && minStr[i + 1] == '1' && minStr[i] == '1')
                {
                    minStr[i] = '0';
                    changed = true;
                }
            }
        }

        int minOnes = count(minStr.begin(), minStr.end(), '1');
        int maxOnes = count(maxStr.begin(), maxStr.end(), '1');

        cout << minOnes << " " << maxOnes << "\n";
    }

    return 0;
}