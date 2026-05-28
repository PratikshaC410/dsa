#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const long long INF = 1e18;

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<long long> pref_max(n);
    pref_max[0] = a[0];
    for (int i = 1; i < n; ++i)
        pref_max[i] = max(pref_max[i - 1], a[i]);
    map<long long, long long> dp;

    dp[1] = a[0] - 1;
    dp[a[0]] = 0;

    for (int i = 1; i < n; ++i)
    {
        int pos = i + 1;
        long long pm = pref_max[i];
        vector<long long> candidates = {1, a[i], pm};
        for (auto const &[val, cost] : dp)
        {
            if (val - 1 >= 1)
                candidates.push_back(val - 1);
            candidates.push_back(val);
            if (val + 1 <= pm)
                candidates.push_back(val + 1);
        }

        vector<long long> valid_candidates;
        for (long long c : candidates)
        {
            if (c >= 1 && c <= pm)
                valid_candidates.push_back(c);
        }
        sort(valid_candidates.begin(), valid_candidates.end());
        valid_candidates.erase(unique(valid_candidates.begin(), valid_candidates.end()), valid_candidates.end());

        map<long long, long long> next_dp;

        if (pos % 2 == 1)
        {
            long long min_prev_cost = INF;
            auto it = dp.rbegin();

            int cand_idx = (int)valid_candidates.size() - 1;
            while (cand_idx >= 0)
            {
                long long cur_val = valid_candidates[cand_idx];

                while (it != dp.rend() && it->first > cur_val)
                {
                    min_prev_cost = min(min_prev_cost, it->second);
                    it++;
                }

                if (min_prev_cost != INF)
                {
                    long long cost_to_change = (cur_val <= a[i]) ? (a[i] - cur_val) : (pm - cur_val);
                    next_dp[cur_val] = min_prev_cost + cost_to_change;
                }
                cand_idx--;
            }
        }
        else
        {
            long long min_prev_cost = INF;
            auto it = dp.begin();

            for (long long cur_val : valid_candidates)
            {
                while (it != dp.end() && it->first < cur_val)
                {
                    min_prev_cost = min(min_prev_cost, it->second);
                    it++;
                }

                if (min_prev_cost != INF)
                {
                    long long cost_to_change = (cur_val <= a[i]) ? (a[i] - cur_val) : (pm - cur_val);
                    next_dp[cur_val] = min_prev_cost + cost_to_change;
                }
            }
        }

        dp = move(next_dp);
    }

    long long ans = INF;
    for (auto const &[val, cost] : dp)
    {
        ans = min(ans, cost);
    }
    cout << ans << "\n";
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