#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int awake_count = 0;
    int forced_sleep_cooldown = 0;

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '1')
        {
            // An important class forces you awake, and resets the cooldown for the next k classes
            awake_count++;
            forced_sleep_cooldown = k;
        }
        else if (forced_sleep_cooldown > 0)
        {
            // A non-important class, but you are forced to stay awake by a previous class
            awake_count++;
            forced_sleep_cooldown--;
        }
        // If s[i] == '0' and forced_sleep_cooldown == 0, you successfully sleep through it!
    }

    // Maximum sleeping classes is total classes minus the ones spent awake
    cout << n - awake_count << "\n";
}

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }
    return 0;
}