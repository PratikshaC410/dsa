#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> b(n);
        for (int i = 0; i < n; i++)
            cin >> b[i];

        sort(b.begin(), b.end(), greater<int>());

        bool valid = true;
        for (int i = 0; i <= n - 3; i++)
        {
            if (b[i] % b[i + 1] != b[i + 2])
            {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            cout << b[0] << " " << b[1] << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }

    return 0;
}