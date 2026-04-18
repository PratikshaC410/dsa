#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Track which seats are already 'covered' (blocked)
    vector<bool> covered(n, false);
    int initial_students = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            initial_students++;
            covered[i] = true;
            if (i > 0)
                covered[i - 1] = true;
            if (i < n - 1)
                covered[i + 1] = true;
        }
    }

    int added_students = 0;
    for (int i = 0; i < n; i++)
    {
        // If we find a seat that is not covered by anyone...
        if (!covered[i])
        {
            added_students++;
            // Place a student at i+1 to cover i, i+1, and i+2
            // If i is the very last seat, we just cover i.
            int placement = i + 1;
            if (placement >= n)
                placement = i;

            // Mark the new coverage
            covered[placement] = true;
            if (placement > 0)
                covered[placement - 1] = true;
            if (placement < n - 1)
                covered[placement + 1] = true;
        }
    }

    cout << initial_students + added_students << endl;
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