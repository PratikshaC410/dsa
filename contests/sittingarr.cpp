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
    long long opened_tables = 0;
    long long total_seated = 0;
    long long empty_seats = 0;
    long long ambiverts_used_as_introverts = 0;

    for (int i = 0; i < n; i++)
    {
        char p = u[i];

        if (p == 'I')
        {
            if (opened_tables < x)
            {
                opened_tables++;
                total_seated++;
                empty_seats += (s - 1);
            }
        }
        else if (p == 'E')
        {
            if (empty_seats > 0)
            {
                empty_seats--;
                total_seated++;
            }
            else if (ambiverts_used_as_introverts > 0)
            {
                ambiverts_used_as_introverts--;
                opened_tables--;
                empty_seats -= (s - 1);

                if (empty_seats > 0)
                {
                    empty_seats--;
                    total_seated++;
                }
            }
        }
        else
        {
            if (opened_tables < x)
            {
                opened_tables++;
                total_seated++;
                empty_seats += (s - 1);
                ambiverts_used_as_introverts++;
            }
            else if (empty_seats > 0)
            {
                empty_seats--;
                total_seated++;
            }
        }
    }

    cout << total_seated << "\n";
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