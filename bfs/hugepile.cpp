#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve()
{
    long long n, k;
    cin >> n >> k;

    if (n == k)
    {
        cout << 0 << "\n";
        return;
    }

    set<long long> current_level;
    current_level.insert(n);

    int minutes = 0;

    while (!current_level.empty())
    {
        set<long long> next_level;
        minutes++;

        bool found = false;
        bool can_split_further = false;

        for (long long x : current_level)
        {
            if (x <= 1)
                continue;

            long long left = x / 2;        // Floor division
            long long right = (x + 1) / 2; // Ceil division

            if (left == k || right == k)
            {
                found = true;
                break;
            }

            if (left > 1)
                next_level.insert(left);
            if (right > 1)
                next_level.insert(right);
        }

        if (found)
        {
            cout << minutes << "\n";
            return;
        }
        if (next_level.empty())
        {
            break;
        }

        current_level = move(next_level);
    }

    cout << -1 << "\n";
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