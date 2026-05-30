#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    long long c;
    cin >> n >> c;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    int coins = 0;
    for (int i = 0; i < n; ++i)
    {
        long long current_weight = a[i];

        for (int j = 0; j < i; ++j)
        {
            if (current_weight > c)
            {
                break;
            }
            current_weight *= 2;
        }

        if (current_weight > c)
        {
            coins++;
        }
    }

    cout << coins << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}