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

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        long long prefix_sum = 0;
        long long min_h = LLONG_MAX;

        for (int i = 0; i < n; i++)
        {
            prefix_sum += a[i];
            min_h = min(min_h, prefix_sum / (i + 1));
            cout << min_h;
            if (i < n - 1)
                cout << " ";
        }
        cout << "\n";
    }

    return 0;
}