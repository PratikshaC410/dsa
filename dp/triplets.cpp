#include <iostream>
#include <vector>

void solve()
{
    long long n;
    std::cin >> n;

    long long total_triples = 0;
    for (long long b = 1; b <= n; ++b)
    {
        long long multiples = n / b;
        total_triples += multiples * multiples;
    }

    std::cout << total_triples << "\n";
}

int main()
{
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}