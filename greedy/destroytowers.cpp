#include <iostream>
#include <vector>
#include <algorithm>
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

    long long final_sum = a[0];
    int current_min = a[0];

    for (int i = 1; i < n; ++i)
    {
        if (a[i] > current_min)
        {
            final_sum += current_min;
        }
        else
        {
            final_sum += a[i];
            current_min = a[i];
        }
    }

    cout << final_sum << "\n";
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
