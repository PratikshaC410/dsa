#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int protected_count = 0;
    // Initialize last_1 to a very small value so the first '1' is far away
    int last_1 = -2000;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            // Check if the current '1' is farther than k-1 from the previous '1'
            if (i - last_1 >= k)
            {
                // Teto could flip this! We must protect it.
                protected_count++;
            }
            // Whether we protected it or it was naturally blocked,
            // this '1' now stays and blocks the next ones.
            last_1 = i;
        }
    }

    cout << protected_count << endl;
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