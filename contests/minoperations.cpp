#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long get_min_ops(long long start, long long target)
{
    if (start == target)
        return 0;

    long long ops = 0;
    while (start > target)
    {
        if (start % 2 == 0)
        {
            start /= 2;
            ops++;
        }
        else
        {
            if (start + 1 == target)
            {
                return ops + 1;
            }
            start = (start + 1) / 2;
            ops += 2;
        }
    }

    if (start == target)
        return ops;
    if (start % 2 != 0 && start + 1 == target)
        return ops + 1;

    return -1; // Unreachable
}

vector<long long> get_all_reachable_states(long long x)
{
    vector<long long> states;
    while (x > 0)
    {
        states.push_back(x);
        if (x == 1)
            break;

        if (x % 2 != 0)
        {
            states.push_back(x + 1);
            x = (x + 1) / 2;
        }
        else
        {
            x /= 2;
        }
    }
    return states;
}

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    bool all_equal = true;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i > 0 && a[i] != a[i - 1])
        {
            all_equal = false;
        }
    }

    if (all_equal)
    {
        cout << 0 << "\n";
        return;
    }

    vector<long long> candidates = get_all_reachable_states(a[0]);

    long long ans = -1;

    for (long long target : candidates)
    {
        long long total_ops = 0;
        bool valid = true;

        for (int i = 0; i < n; i++)
        {
            long long cost = get_min_ops(a[i], target);
            if (cost == -1)
            {
                valid = false;
                break;
            }
            total_ops += cost;
        }

        if (valid)
        {
            if (ans == -1 || total_ops < ans)
            {
                ans = total_ops;
            }
        }
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