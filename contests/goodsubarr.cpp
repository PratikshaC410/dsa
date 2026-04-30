#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    vector<long long> p(n + 1, 0);

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (i % 2 == 1)
        {
            p[i] = p[i - 1] + a[i];
        }
        else
        {
            p[i] = p[i - 1] - a[i];
        }
    }

    long long count = 0;
    map<long long, int> even_indices;
    map<long long, int> odd_indices;

    even_indices[0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        if (i % 2 == 0)
        {
            count += even_indices[p[i]];
            even_indices[p[i]]++;
        }
        else
        {
            count += odd_indices[p[i]];
            odd_indices[p[i]]++;
        }
    }

    cout << count << "\n";
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