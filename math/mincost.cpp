#include <iostream>
#include <vector>

using namespace std;

vector<long long> precompute_powers(int max_power)
{
    vector<long long> pow3(max_power + 1, 1);
    for (int i = 1; i <= max_power; ++i)
    {
        pow3[i] = pow3[i - 1] * 3;
    }
    return pow3;
}

void solve()
{
    long long n;
    cin >> n;

    auto pow3 = precompute_powers(25);

    long long total_cost = 0;
    int x = 0;

    while (n > 0)
    {
        int digit = n % 3;
        n /= 3;

        if (digit > 0)
        {
            long long cost_per_deal = 0;
            if (x == 0)
            {
                cost_per_deal = 3; // 3^(0+1) + 0 * 3^(-1) = 3
            }
            else
            {
                cost_per_deal = pow3[x + 1] + x * pow3[x - 1];
            }
            total_cost += digit * cost_per_deal;
        }
        x++;
    }

    cout << total_cost << "\n";
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