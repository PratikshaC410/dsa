#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        bool found = false;

        for (int i = 0; i < n && !found; i++)
        {
            for (int j = i + 1; j < n && !found; j++)
            {
                if (a[i] < a[j] && (a[j] % a[i]) % 2 == 0)
                {
                    cout << a[i] << " " << a[j] << '\n';
                    found = true;
                }
            }
        }

        if (!found)
        {
            cout << -1 << '\n';
        }
    }

    return 0;
}