#include <bits/stdc++.h>
using namespace std;

bool valid(int p, int q)
{
    return p <= 2 * (q + 1) && q <= 2 * (p + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (valid(a, b) && valid(c - a, d - b))
            cout << "YES yess\n";
        else
            cout << "NO\n";
    }
    return 0;
}
