#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;

        int totalStudents = 0;

        for (char c : s)
        {
            if (c == '1')
                totalStudents++;
        }

        int i = 0;
        while (i < n)
        {
            if (s[i] == '0')
            {
                int gapStart = i;
                while (i < n && s[i] == '0')
                {
                    i++;
                }
                int gapLen = i - gapStart;

                bool hasLeftNeighbor = (gapStart > 0 && s[gapStart - 1] == '1');
                bool hasRightNeighbor = (i < n && s[i] == '1');
                bool isMiddleGap = hasLeftNeighbor && hasRightNeighbor;

                int toAdd;
                if (isMiddleGap)
                {
                    toAdd = (gapLen - 1) / 2;
                }
                else
                {
                    toAdd = max(1, gapLen / 2);
                }

                totalStudents += toAdd;
            }
            else
            {
                i++;
            }
        }

        cout << totalStudents << "\n";
    }

    return 0;
}