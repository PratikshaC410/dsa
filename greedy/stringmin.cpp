#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Initialize string s with 'm' characters of 'B'
    // Using 1-based indexing logic, so we'll handle offsets carefully
    string s(m, 'B');

    for (int i = 0; i < n; i++)
    {
        // Calculate the two possible 0-indexed positions
        int pos1 = a[i] - 1;
        int pos2 = (m + 1 - a[i]) - 1;

        int left = min(pos1, pos2);
        int right = max(pos1, pos2);

        // Greedy choice: try to put 'A' at the leftmost position first
        if (s[left] == 'B')
        {
            s[left] = 'A';
        }
        else
        {
            // If left is already 'A', put it at the right position
            s[right] = 'A';
        }
    }

    cout << s << endl;
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