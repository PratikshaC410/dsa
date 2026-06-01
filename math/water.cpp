#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

// Safe LCM function to prevent overflow using __int128
long long safe_lcm(long long x, long long y, long long m)
{
    long long g = std::gcd(x, y);
    // __int128 prevents overflow during multiplication
    __int128 lcm_val = (__int128)x * (y / g);
    if (lcm_val > m)
    {
        return m + 1; // Return a value greater than m so m / lcm becomes 0
    }
    return (long long)lcm_val;
}

void solve()
{
    long long a, b, c, m;
    cin >> a >> b >> c >> m;

    // Calculate LCMs safely
    long long lcm_ab = safe_lcm(a, b, m);
    long long lcm_bc = safe_lcm(b, c, m);
    long long lcm_ac = safe_lcm(a, c, m);
    long long lcm_abc = safe_lcm(lcm_ab, c, m);

    // Total intersection counts
    long long n_a = m / a;
    long long n_b = m / b;
    long long n_c = m / c;

    long long n_ab = m / lcm_ab;
    long long n_bc = m / lcm_bc;
    long long n_ac = m / lcm_ac;
    long long n_abc = m / lcm_abc;

    // Exclusive day breakdowns
    long long days_abc = n_abc;

    long long days_ab = n_ab - n_abc;
    long long days_bc = n_bc - n_abc;
    long long days_ac = n_ac - n_abc;

    long long days_a = n_a - days_ab - days_ac - days_abc;
    long long days_b = n_b - days_ab - days_bc - days_abc;
    long long days_c = n_c - days_ac - days_bc - days_abc;

    // Water calculations
    long long water_a = (6 * days_a) + (3 * days_ab) + (3 * days_ac) + (2 * days_abc);
    long long water_b = (6 * days_b) + (3 * days_ab) + (3 * days_bc) + (2 * days_abc);
    long long water_c = (6 * days_c) + (3 * days_ac) + (3 * days_bc) + (2 * days_abc);

    cout << water_a << " " << water_b << " " << water_c << "\n";
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