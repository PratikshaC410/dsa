#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s, z;
    cin >> s >> z;

    vector<long long> type_count(4, 0);
    for (int j = 0; j < n; j++)
    {
        int mask = ((s[j] - '0') << 1) | (z[j] - '0');
        type_count[mask]++;
    }

    long long x_00 = 0;
    long long x_01 = type_count[1] + type_count[3]; // z[j] = 1
    long long x_10 = type_count[2] + type_count[3]; // s[j] = 1
    long long x_11 = type_count[1] + type_count[2]; // s[j] ^ z[j] = 1

    vector<long long> coeff_freq(4, 0);
    coeff_freq[2] = 1; // State (1,0)
    coeff_freq[1] = 1;
    if (k == 1)
    {
        coeff_freq[3] = 1;
    }
    else
    {
        long long total_elements = (1LL << k) + 1;
        long long state3 = ((1LL << k) - (k % 2 == 0 ? 1 : -1)) / 3;
        long long state12 = (total_elements - state3) / 2;

        coeff_freq[0] = 0;
        coeff_freq[1] = state12; // (0,1)
        coeff_freq[2] = state12; // (1,0)
        coeff_freq[3] = state3;  // (1,1)
    }

    long long total_sum = 0;
    vector<long long> x_val = {x_00, x_01, x_10, x_11};

    for (int c = 0; c < 4; c++)
    {
        long long x = x_val[c];
        long long y = n - x;
        total_sum += coeff_freq[c] * x * y;
    }

    cout << total_sum << "\n";
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