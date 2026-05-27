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
        vector<long long> even;
        bool hasOne = false;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 1)
                hasOne = true;
            if (a[i] % 2 == 0)
                even.push_back(a[i]);
        }

        if (hasOne)
        {
            cout << 1 << " " << a[1] << '\n';
        }
        else if (even.size() >= 2)
        {
            cout << even[0] << " " << even[1] << '\n';
        }
        else
        {
            bool found = false;

            if (even.size() == 1)
            {
                long long y = even[0];
                for (int i = 0; i < n; i++)
                {
                    if (a[i] < y && (y / a[i]) % 2 == 0)
                    {
                        cout << a[i] << " " << y << '\n';
                        found = true;
                        break;
                    }
                }
            }

            if (!found)
            {
                for (int i = 0; i < n; i++)
                {
                    if (i + 1 < n && (a[i + 1] % a[i]) % 2 == 0)
                    {
                        cout << a[i] << " " << a[i + 1] << '\n';
                        found = true;
                        break;
                    }
                    if (i + 2 < n && (a[i + 2] % a[i]) % 2 == 0)
                    {
                        cout << a[i] << " " << a[i + 2] << '\n';
                        found = true;
                        break;
                    }
                }
            }

            if (!found)
            {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}