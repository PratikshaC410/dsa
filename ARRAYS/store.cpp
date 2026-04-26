#include <iostream>
#include <vector>
#include <bits/std++.h>
using namespace std;

/**
 * Problem Logic:
 * A sofa can be ordered if and only if it is the FIRST sofa in the list
 * that is less than or equal to the customer's budget.
 * * Therefore, a sofa at index i is ONLY reachable if its price is strictly
 * lower than the minimum price of all sofas appearing before it.
 */

void solve()
{
    int n;
    if (!(cin >> n))
        return;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // If there's no sofa, nothing to report
    if (n == 0)
        return;

    vector<int> impossible_indices;
    int current_min = a[0];

    // The first sofa (index 1) is always reachable with budget m = a[0]
    // We check every sofa from the second one (index 1 in 0-based array)
    for (int i = 1; i < n; i++)
    {
        // Since prices are unique, if a[i] is greater than current_min,
        // it's shielded. Even if they weren't unique, >= would apply.
        if (a[i] > current_min)
        {
            impossible_indices.push_back(i + 1); // Store 1-based index
        }
        else
        {
            // New minimum price found; this sofa is reachable!
            current_min = a[i];
        }
    }

    // Output results for this test case
    cout << impossible_indices.size() << "\n";
    for (int i = 0; i < impossible_indices.size(); i++)
    {
        cout << impossible_indices[i] << (i == impossible_indices.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main()
{
    // Standard CP optimization for faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        solve();
    }
    return 0;
}