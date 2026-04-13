#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve()
{
    int n;
    if (!(cin >> n))
        return;
    string s;
    cin >> s;

    int L = 1, R = n;
    vector<int> a(n);

    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] == '<')
        {
            // a[i+1] must be smaller than everything before it.
            a[i + 1] = L++;
        }
        else
        {
            // a[i+1] must be larger than everything before it.
            a[i + 1] = R--;
        }
    }

    // The only remaining number is for the first position.
    a[0] = L;

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
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