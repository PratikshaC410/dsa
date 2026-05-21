#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Step 1: Check if it's already sorted
    bool already_sorted = true;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            already_sorted = false;
            break;
        }
    }
    if (already_sorted)
    {
        cout << "Yes\n";
        return;
    }

    // Step 2: Find the first inversion to determine what 'k' needs to be
    long long max_so_far = a[0];
    long long k = -1;

    for (int i = 1; i < n; i++)
    {
        if (a[i] < max_so_far)
        {
            k = max_so_far - a[i];
            break;
        }
        max_so_far = max(max_so_far, a[i]);
    }

    // Step 3: Verify if this specific value of 'k' can fix the array
    // We simulate creating a valid sorted array using greedily chosen additions
    long long prev = -1;
    bool possible = true;

    for (int i = 0; i < n; i++)
    {
        // Option 1: Keep the element as is
        long long option1 = a[i];
        // Option 2: Boost the element by k
        long long option2 = a[i] + k;

        if (i == 0)
        {
            // For the first element, we prefer the smaller option to leave room
            prev = option1;
        }
        else
        {
            // We want to pick the smallest valid option that is >= prev
            if (option1 >= prev)
            {
                prev = option1;
            }
            else if (option2 >= prev)
            {
                prev = option2;
            }
            else
            {
                // Neither option is large enough to maintain non-decreasing order
                possible = false;
                break;
            }
        }
    }

    if (possible)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}

int main()
{
    // Fast I/O for competitive programming
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
