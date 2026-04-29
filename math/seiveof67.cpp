#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    bool found = false;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        if (a == 67)
        {
            found = true;
        }
    }

    if (found)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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