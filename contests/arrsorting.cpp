#include <bits/stdc++.h>
using namespace std;

bool checkMask(vector<long long> &a, vector<bool> &increase)
{
    int n = a.size();
    long long min_k = 1;
    long long max_k = 2000000000LL;
    bool valid = true;

    for (int i = 1; i < n; i++)
    {
        if (increase[i] && !increase[i - 1])
        {
            long long need = a[i - 1] - a[i];
            if (need >= 1)
            {
                min_k = max(min_k, need);
            }
        }
        else if (!increase[i] && increase[i - 1])
        {
            long long limit = a[i] - a[i - 1];
            max_k = min(max_k, limit);
        }
        else if (!increase[i] && !increase[i - 1])
        {
            if (a[i] < a[i - 1])
            {
                valid = false;
                break;
            }
        }
        else
        {
            if (a[i] < a[i - 1])
            {
                valid = false;
                break;
            }
        }
    }

    return valid && min_k <= max_k && min_k >= 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // Check if already sorted
        bool sorted = true;
        for (int i = 1; i < n; i++)
        {
            if (a[i] < a[i - 1])
            {
                sorted = false;
                break;
            }
        }

        if (sorted)
        {
            cout << "Yes\n";
            continue;
        }

        bool found = false;

        if (n <= 20)
        {
            // Try all 2^n subsets
            for (int mask = 0; mask < (1 << n); mask++)
            {
                vector<bool> increase(n, false);
                for (int i = 0; i < n; i++)
                {
                    if (mask & (1 << i))
                    {
                        increase[i] = true;
                    }
                }

                if (checkMask(a, increase))
                {
                    found = true;
                    break;
                }
            }
        }
        else
        {
            // For large n, try different split strategies
            // Strategy 1: Try increasing suffix starting at each position
            for (int start = 0; start < n && !found; start++)
            {
                vector<bool> increase(n, false);
                for (int i = start; i < n; i++)
                {
                    increase[i] = true;
                }
                if (checkMask(a, increase))
                {
                    found = true;
                }
            }

            // Strategy 2: Try a greedy approach - go left to right and decide
            if (!found)
            {
                for (int first_bad = 0; first_bad < n && !found; first_bad++)
                {
                    // Find the first position where a[i] > a[i+1]
                    if (first_bad == 0 || a[first_bad] < a[first_bad - 1])
                    {
                        // Try: increase all elements from first_bad onwards
                        vector<bool> increase(n, false);
                        for (int i = first_bad; i < n; i++)
                        {
                            increase[i] = true;
                        }
                        if (checkMask(a, increase))
                        {
                            found = true;
                        }
                    }
                }
            }
        }

        cout << (found ? "Yes" : "No") << "\n";
    }

    return 0;
}
