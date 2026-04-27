#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    long long m;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    // The best oven is always collected at the very last second m
    long long total_cakes = a[n - 1] * m;

    // For the other ovens, we collect them at seconds m-1, m-2...
    // We can collect at most (m-1) other ovens.
    long long current_second = m - 1;

    // Iterate through the other n-1 ovens from largest to smallest
    for (int i = n - 2; i >= 0; i--)
    {
        if (current_second <= 0)
            break;

        total_cakes += (a[i] * current_second);
        current_second--;
    }

    cout << total_cakes << endl;
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