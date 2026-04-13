#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int L = 1, R = n;
    vector<int> a(n);

    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == '<')
        {
            // Next stick must be smaller than all previous.
            //  place the current largest available number.
            a[i] = R--;
        }
        else
        {
            // Next stick must be larger than all previous.
            //  place the current smallest available number.
            a[i] = L++;
        }
    }
    a[n - 1] = L;

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