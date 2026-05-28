#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    map<int, int> required;
    required[0] = 3;
    required[1] = 1;
    required[2] = 2;
    required[3] = 1;
    required[5] = 1;

    map<int, int> current_counts;

    for (int i = 0; i < n; ++i)
    {
        current_counts[a[i]]++;

        bool possible = true;
        for (auto const &pair : required)
        {
            int digit = pair.first;
            int needed_count = pair.second;

            if (current_counts[digit] < needed_count)
            {
                possible = false;
                break;
            }
        }

        if (possible)
        {
            cout << i + 1 << "\n";
            return;
        }
    }

    cout << 0 << "\n";
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