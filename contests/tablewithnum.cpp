#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n, h, l;
    cin >> n >> h >> l;
    int ch = 0, cl = 0, ceither = 0;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        bool useful = false;
        if (a <= h)
        {
            ch++;
            useful = true;
        }
        if (a <= l)
        {
            cl++;
            useful = true;
        }
        if (useful)
        {
            ceither++;
        }
    }
    cout << min({ch, cl, ceither / 2}) << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}