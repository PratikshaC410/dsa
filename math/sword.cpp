#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    vector<long long> b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }

    sort(a.begin(), a.end(), greater<long long>());

    vector<long long> pref_b(n);
    pref_b[0] = b[0];
    for (int i = 1; i < n; ++i)
    {
        pref_b[i] = pref_b[i - 1] + b[i];
    }

    long long max_score = 0;

    for (int mid = 1; mid <= n; ++mid)
    {
        long long required_strikes = pref_b[mid - 1];

        // If we have enough total swords to cover the strikes for 'mid' levels
        if (required_strikes <= n)
        {
            long long current_x = a[required_strikes - 1];
            long long current_score = (long long)mid * current_x;

            max_score = max(max_score, current_score);
        }
    }

    cout << max_score << "\n";
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