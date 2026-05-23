#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long k = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            k = max(k, a[i - 1] - a[i]);
        }
    }

    if (k == 0)
    {
        cout << "Yes\n";
        return;
    }
    long long prev_val = a[0];
    bool possible = true;

    for (int i = 1; i < n; i++)
    {
        if (a[i] >= prev_val)
        {
            prev_val = a[i];
        }
        else if (a[i] + k >= prev_val)
        {
            prev_val = a[i] + k;
        }
        else
        {
            possible = false;
            break;
        }
    }

    if (possible)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
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
