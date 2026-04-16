#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canWinNim(int n)
    {

        return n % 4 != 0;
    }
};

int main()
{
    Solution sol;

    cout << "n\tCanWin\n";
    cout << "---\t------\n";
    for (int n : testCases)
    {
        cout << n << "\t" << (sol.canWinNim(n) ? "true" : "false") << "\n";
    }

    return 0;
}