#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int operations = 0;
    int current_max = -1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > current_max)
        {

            current_max = a[i];
            operations++;
        }
    }

    cout << operations << endl;
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