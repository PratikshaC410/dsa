#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve()
{
    string s;
    cin >> s;

    int n = s.length();
    string target = "";

    for (int i = 0; i < n / 2; ++i)
    {
        target += "()";
    }
    if (s == target)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
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