#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    long long c, k;
    if (!(cin >> n >> c >> k))
        return;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
    {

        if (a[i] <= c)
        {
            long long can_add = c - a[i];
            long long used = min(k, can_add);
            c += (a[i] + used);

            k -= used;
        }
        else
        {
            break;
        }
    }

    cout << c << endl;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}