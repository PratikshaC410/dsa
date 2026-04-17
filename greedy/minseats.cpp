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

                bool isLeading = (gapStart == 0);
                bool isTrailing = (i == n);

                if (isLeading || isTrailing)
                {
                    totalStudents += gapLen / 2;
                }
                else
                {

                    totalStudents += (gapLen + 1) / 2;
                }
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