#include <iostream>

using namespace std;

void solve()
{
    long long a, b, n;
    cin >> a >> b >> n;
    long long capacity = a / b;
    cout << (n + capacity - 1) / capacity << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}