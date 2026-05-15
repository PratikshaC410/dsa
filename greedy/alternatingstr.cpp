#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    string s_prime = s;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 1)
        {
            s_prime[i] = (s_prime[i] == 'a') ? 'b' : 'a';
        }
    }
    int transitions = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s_prime[i] != s_prime[i + 1])
        {
            transitions++;
        }
    }

    if (transitions <= 2)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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