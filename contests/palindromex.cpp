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
        cin >> n;
        vector<int> a(2 * n);

        for (int i = 0; i < 2 * n; i++)
        {
            cin >> a[i];
        }

        int maxMex = 0;
        for (int l = 0; l < 2 * n; l++)
        {
            for (int r = l; r < 2 * n; r++)
            {
                bool isPalindrome = true;
                for (int i = 0; i < (r - l + 1) / 2; i++)
                {
                    if (a[l + i] != a[r - i])
                    {
                        isPalindrome = false;
                        break;
                    }
                }

                if (isPalindrome)
                {
                    // Compute MEX of this subarray
                    set<int> elements;
                    for (int i = l; i <= r; i++)
                    {
                        elements.insert(a[i]);
                    }

                    int mex = 0;
                    while (elements.count(mex))
                    {
                        mex++;
                    }

                    maxMex = max(maxMex, mex);
                }
            }
        }

        cout << maxMex << "\n";
    }

    return 0;
}