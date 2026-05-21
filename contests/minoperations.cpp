#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);

    map<long long, long long> total_steps;
    map<long long, int> reach_count;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        long long x = a[i];
        long long steps = 0;

        vector<pair<long long, long long>> current_path;
        current_path.push_back(make_pair(x, steps));

        while (x > 2)
        {
            if (x % 2 == 0)
            {
                x /= 2;
            }
            else
            {
                x += 1;
            }
            steps++;
            current_path.push_back(make_pair(x, steps));
        }

        if (x == 2)
        {
            current_path.push_back(make_pair(1, steps + 1));
        }
        else if (x == 1)
        {
            current_path.push_back(make_pair(2, steps + 1));
        }

        sort(current_path.begin(), current_path.end());

        for (size_t j = 0; j < current_path.size(); j++)
        {
            if (j == 0 || current_path[j].first != current_path[j - 1].first)
            {
                long long val = current_path[j].first;
                long long cost = current_path[j].second;

                total_steps[val] += cost;
                reach_count[val]++;
            }
        }
    }

    long long min_ops = -1;

    for (map<long long, int>::const_iterator it = reach_count.begin(); it != reach_count.end(); ++it)
    {
        long long val = it->first;
        int count = it->second;

        if (count == n)
        {
            if (min_ops == -1 || total_steps[val] < min_ops)
            {
                min_ops = total_steps[val];
            }
        }
    }

    cout << min_ops << "\n";
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
