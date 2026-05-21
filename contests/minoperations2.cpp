#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long get_steps(long long x, long long target)
{
    long long steps = 0;
    while (x != target)
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
    }
    return steps;
}

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);

    bool already_equal = true;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i > 0 && a[i] != a[i - 1])
        {
            already_equal = false;
        }
    }

    if (already_equal)
    {
        cout << 0 << "\n";
        return;
    }

    long long total_to_1 = 0;
    long long total_to_2 = 0;

    for (int i = 0; i < n; i++)
    {
        total_to_1 += get_steps(a[i], 1);
        total_to_2 += get_steps(a[i], 2);
    }

    cout << min(total_to_1, total_to_2) << "\n";
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