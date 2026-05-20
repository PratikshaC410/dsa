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

        vector<int> a(n);

        map<int, int> freq;

        bool ok = false;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];

            freq[a[i]]++;

            if (freq[a[i]] >= 2)
                ok = true;
        }

        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
