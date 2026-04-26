#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<long long> pref(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        // Build prefix sum array
        pref[i] = pref[i - 1] + a[i];
    }

    // Try all possible split points l and r
    // 1 <= l < r < n ensures prefix, middle, and suffix are non-empty
    for (int l = 1; l < n - 1; l++)
    {
        for (int r = l + 1; r < n; r++)
        {
            // Calculate segment sums using prefix sums
            int s1 = pref[l] % 3;
            int s2 = (pref[r] - pref[l]) % 3;
            int s3 = (pref[n] - pref[r]) % 3;

            // Condition: All same OR all different
            bool all_same = (s1 == s2 && s2 == s3);
            bool all_diff = (s1 != s2 && s1 != s3 && s2 != s3);

            if (all_same || all_diff)
            {
                cout << l << " " << r << endl;
                return;
            }
        }
    }

    // If no valid partition is found after checking all pairs
    cout << "0 0" << endl;
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