#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    if (!(cin >> n))
        return;

    int operations = 0;
    int current_max = -1;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;

        // The core logic:
        // If the number is greater than or equal to our current max,
        // it will be a "rightmost maximum" in some step of the process.
        if (val >= current_max)
        {
            current_max = val;
            operations++;
        }
    }
    cout << operations << "\n";
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