#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void solve()
{
    string n;
    cin >> n;

    int total_len = n.length();
    int max_keep = 0;
    int current_zeros = 0;

    for (int i = 0; i < total_len; ++i)
    {
        if (n[i] == '0')
        {
            current_zeros++;
        }
        else
        {
            max_keep = max(max_keep, current_zeros + 1);
        }
    }

    cout << total_len - max_keep << endl;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}