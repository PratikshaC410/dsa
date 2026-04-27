#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int e = 0; // Pointer for even numbers
    int o = 0; // Pointer for odd numbers

    for (int i = 0; i < n; ++i)
    {
        // Advance e to the next even number
        while (e < n && (a[e] & 1))
            e++;
        // Advance o to the next odd number
        while (o < n && !(a[o] & 1))
            o++;

        if (e < n && o < n)
        {
            if (a[e] < a[o])
            {
                cout << a[e++] << " ";
            }
            else
            {
                cout << a[o++] << " ";
            }
        }
        else if (e < n)
        {
            cout << a[e++] << " ";
        }
        else if (o < n)
        {
            cout << a[o++] << " ";
        }
    }
    cout << '\n';
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