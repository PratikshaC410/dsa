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

        map<int, int> freq;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            freq[x]++;
        }

        int mx = 0;
        for (auto &[v, f] : freq)
            mx = max(mx, f);

        if (mx <= (n + 1) / 2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}