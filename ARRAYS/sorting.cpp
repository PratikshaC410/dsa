#include <iostream>
#include <vector>
#include <cmath>
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

    long long target_val = abs(a[0]);

    vector<long long> magnitudes(n);
    for (int i = 0; i < n; ++i)
    {
        magnitudes[i] = abs(a[i]);
    }

    sort(magnitudes.begin(), magnitudes.end());

    int current_idx = 0;
    for (int i = 0; i < n; ++i)
    {
        if (magnitudes[i] == target_val)
        {
            current_idx = i;
            break;
        }
    }

    int target_median_idx = (n + 1) / 2 - 1;

    int shifts_needed = target_median_idx - current_idx;
    int elements_larger = n - 1 - current_idx;

    bool can_shift_to_positive_median = (shifts_needed >= 0 && shifts_needed <= elements_larger);

    bool can_shift_to_negative_median = (target_median_idx <= elements_larger);

    if (can_shift_to_positive_median || can_shift_to_negative_median)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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