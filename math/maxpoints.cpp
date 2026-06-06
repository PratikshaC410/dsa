#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    int odd_count = 0;
    int even_count = 0;

    for (int i = 0; i < n; ++i)
    {
        long long a;
        cin >> a;
        if (a % 2 != 0)
        {
            odd_count++;
        }
        else
        {
            even_count++;
        }
    }

    if (odd_count == 0)
    {
        cout << 1 << "\n";
    }
    else if (even_count > 0)
    {
        cout << odd_count + 1 << "\n";
    }
    else
    {
        cout << odd_count - 1 << "\n";
    }
}

int main()
{
    // Fast I/O
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
