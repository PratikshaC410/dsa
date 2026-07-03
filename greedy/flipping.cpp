#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    vector<int> operations;
    int flip_count = 0;

    for (int i = n; i >= 1; --i)
    {
        long long current_val = a[i];
        if (flip_count % 2 != 0)
        {
            current_val = -current_val;
        }

        if (current_val > 0)
        {
            operations.push_back(i);
            flip_count++;
        }
    }

    cout << operations.size() << "\n";
    for (int i = 0; i < operations.size(); ++i)
    {
        cout << operations[i] << (i == operations.size() - 1 ? "" : " ");
    }
    cout << "\n";
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