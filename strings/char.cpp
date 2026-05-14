#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    string r;
    cin >> r;
    int n = r.length();

    int first_s = -1, last_s = -1;
    for (int i = 0; i < n; i++)
    {
        if (r[i] == 's')
        {
            if (first_s == -1)
                first_s = i;
            last_s = i;
        }
    }

    if (first_s == -1)
    {
        cout << n - 2 << endl;
        return;
    }

    int ops = 0;
    ops += first_s;
    ops += (n - 1 - last_s);

    int current_u_count = 0;
    for (int i = first_s; i <= last_s; i++)
    {
        if (r[i] == 'u')
        {
            current_u_count++;
        }
        else
        {
            if (current_u_count > 1)
            {
                ops += (current_u_count - 1);
            }
            current_u_count = 0;
        }
    }

    cout << ops << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}