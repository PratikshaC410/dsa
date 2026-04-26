#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> freq;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        freq[x]++;
    }
    vector<int> counts;
    for (auto const &[val, count] : freq)
    {
        counts.push_back(count);
    }
    sort(counts.begin(), counts.end());

    int max_balanced_len = 0;
    int num_distinct = counts.size();

    for (int i = 0; i < num_distinct; ++i)
    {
        int k = counts[i];
        int current_len = k * (num_distinct - i);
        max_balanced_len = max(max_balanced_len, current_len);
    }

    cout << max_balanced_len << endl;
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