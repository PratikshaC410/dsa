#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int k = 0; k <= n; k++)
    {
        bool possible = true;

        for (int i = 0; i < n - k; i++)
        {
            if (a[i] > b[i + k])
            {
                possible = false;
                break;
            }
        }

        if (possible)
        {
            cout << k << endl;
            return;
        }
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