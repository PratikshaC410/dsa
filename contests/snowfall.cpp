#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> m6, m2, m3, none;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x % 6 == 0)
            m6.push_back(x);
        else if (x % 2 == 0)
            m2.push_back(x);
        else if (x % 3 == 0)
            m3.push_back(x);
        else
            none.push_back(x);
    }

    vector<int> res;
    for (int x : m6)
        res.push_back(x);
    for (int x : m2)
        res.push_back(x);
    for (int x : none)
        res.push_back(x);
    for (int x : m3)
        res.push_back(x);

    for (int i = 0; i < n; i++)
    {
        cout << res[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}