#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int total_bal = 0;
    for (char c : s)
    {
        if (c == '(')
            total_bal++;
        else
            total_bal--;
    }

    // Total '(' must equal total ')'
    if (total_bal != 0)
    {
        cout << "NO" << endl;
        return;
    }

    // Find the first point of imbalance from the left
    int L = -1, bal = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            bal++;
        else
            bal--;
        if (bal < 0)
        {
            L = i;
            break;
        }
    }

    //  it's already an RBS
    if (L == -1)
    {
        cout << "YES" << endl;
        return;
    }

    // Find the first point of imbalance from the right
    int R = -1;
    bal = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == ')')
            bal++;
        else
            bal--;
        if (bal < 0)
        {
            R = i;
            break;
        }
    }
    // check for the left and right once internally for safer side

    int cur = 0;
    for (int i = 0; i < L; i++)
    {
        if (s[i] == '(')
            cur++;
        else
            cur--;
        if (cur < 0)
        {
            cout << "NO" << endl;
            return;
        }
    }

    cur = 0;
    for (int i = n - 1; i > R; i--)
    {
        if (s[i] == ')')
            cur++;
        else
            cur--;
        if (cur < 0)
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}