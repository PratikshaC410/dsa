#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        int xor_sum = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            xor_sum ^= a[i];
        }

        if (xor_sum != 0)
        {
            cout << "YES\n";
        }
        else if (n % 2 == 1)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}