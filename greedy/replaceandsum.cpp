#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<long long> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    vector<long long> best_at_pos(n + 1);
    for (int i = 1; i <= n; i++)
    {
        best_at_pos[i] = max(a[i], b[i]);
    }

    vector<long long> suffix_max(n + 2, 0);
    for (int i = n; i >= 1; i--)
    {
        suffix_max[i] = max(best_at_pos[i], suffix_max[i + 1]);
    }

    vector<long long> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + suffix_max[i];
    }

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        long long ans = pref[r] - pref[l - 1];
        cout << ans << (i == q - 1 ? "" : " ");
    }
    cout << "\n";
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