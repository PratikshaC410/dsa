#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve()
{
    int n, x, s;
    cin >> n >> x >> s;
    string u;
    cin >> u;

    // Track total capacities directly
    long long open_tables = 0;
    long long total_seated = 0;
    long long available_seats = 0;

    // Number of tables opened by an 'A' that can be given up later
    long long flexible_tables = 0;

    for (int i = 0; i < n; i++)
    {
        char p = u[i];

        if (p == 'I')
        {
            if (open_tables < x)
            {
                open_tables++;
                total_seated++;
                available_seats += (s - 1);
            }
            else if (flexible_tables > 0)
            {
                // Regret: An Ambivert opened a table, but a strict Introvert needs it more.
                // Convert that past Ambivert into an Extrovert, giving their table slot to this 'I'.
                flexible_tables--;
                available_seats--;          // Past 'A' now consumes a seat
                total_seated++;             // This 'I' sits down
                available_seats += (s - 1); // New table brings seats
            }
        }
        else if (p == 'E')
        {
            if (available_seats > 0)
            {
                available_seats--;
                total_seated++;
            }
        }
        else
        { // p == 'A'
            // Ambiverts always prefer opening a table if slots are open,
            // because a table adds s-1 seats for future Extroverts.
            if (open_tables < x && s > 1)
            {
                open_tables++;
                total_seated++;
                available_seats += (s - 1);
                flexible_tables++;
            }
            else if (available_seats > 0)
            {
                available_seats--;
                total_seated++;
            }
            else if (open_tables < x)
            {
                // Even if s == 1, open a table if we have no other options
                open_tables++;
                total_seated++;
                available_seats += (s - 1);
            }
        }

        // If conversions caused a seat deficit, correct it immediately
        if (available_seats < 0)
        {
            total_seated = total_seated + available_seats;
            available_seats = 0;
        }
    }

    cout << total_seated << "\n";
}

int main()
{
    // Crucial for performance on large 200,000 stream scales
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