#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;

        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
        }

        cout << __lg(n) << "\n";
    }

    return 0;
}