#include <iostream>
#include <vector>

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

    if (n == 0)
    {
        cout << 0 << endl
             << endl;
        return;
    }

    vector<int> impossible_indices;
    int current_min = a[0];

    // Check each sofa starting from the second one
    for (int i = 1; i < n; i++)
    {
        if (a[i] >= current_min)
        {
            // This sofa is "shielded" by a cheaper or equal-priced
            // sofa that appeared earlier in the list.
            impossible_indices.push_back(i + 1); // 1-based indexing
        }
        else
        {
            // This sofa becomes the new price floor
            current_min = a[i];
        }
    }

    // Output the count
    cout << impossible_indices.size() << endl;

    // Output the indices
    for (int i = 0; i < impossible_indices.size(); i++)
    {
        cout << impossible_indices[i] << (i == impossible_indices.size() - 1 ? "" : " ");
    }
    cout << endl;
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