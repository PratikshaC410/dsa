#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    string s;
    cin >> s;

    int n = s.length();
    int count_4 = 0;

    vector<int> pref_2(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        pref_2[i + 1] = pref_2[i] + (s[i] == '2');
        if (s[i] == '4')
        {
            count_4++;
        }
    }

    vector<int> suff_13(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        suff_13[i] = suff_13[i + 1] + (s[i] == '1' || s[i] == '3');
    }

    //   partition point to transition from 2s to (1s and 3s)
    int max_kept = 0;
    for (int i = 0; i <= n; i++)
    {
        // pref_2[i] is the number of '2's up to index i
        // suff_13[i] is the number of '1's and '3's from index i to the end
        max_kept = max(max_kept, pref_2[i] + suff_13[i]);
    }

    // Minimum deletions = total elements - elements we have to delete anyway (4s) - max elements we can save
    int min_deletions = n - count_4 - max_kept;

    cout << min_deletions + count_4 << "\n";
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