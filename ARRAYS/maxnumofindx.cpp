#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        map<long long, int> diff;
        int count = 0;
        int base_count = 0;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[i])
            {
                long long start_k = (a[i] + a[j]) / 2 + 1;
                diff[start_k]++;
            }
            else if (a[j] < a[i])
            {
                long long end_k = (a[i] + a[j] + 1) / 2;
                if ((a[i] + a[j]) % 2 == 0)
                    end_k = (a[i] + a[j]) / 2;

                base_count++;
                diff[end_k]--;
            }
        }

        int max_j = base_count;
        int current = base_count;
        for (auto const &[val, d] : diff)
        {
            current += d;
            max_j = max(max_j, current);
        }
        cout << max_j << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}