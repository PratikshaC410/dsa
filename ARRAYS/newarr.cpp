#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> result;
vector<int> used_count;
vector<int> first_pos;

bool backtrack(int pos)
{
    // Base case: filled all positions
    if (pos == 2 * n)
    {
        return true;
    }

    // Try numbers in descending order (larger numbers first)
    for (int num = n; num >= 1; num--)
    {
        if (used_count[num] == 2)
        {
            continue; // Already placed twice
        }

        if (used_count[num] == 0)
        {
            // First occurrence of this number
            result[pos] = num;
            first_pos[num] = pos;
            used_count[num] = 1;

            if (backtrack(pos + 1))
            {
                return true;
            }

            // Backtrack
            result[pos] = 0;
            first_pos[num] = -1;
            used_count[num] = 0;
        }
        else
        {
            // Second occurrence - check distance constraint
            int fp = first_pos[num];
            int distance = pos - fp;

            // Distance must be divisible by num
            if (distance % num == 0)
            {
                result[pos] = num;
                used_count[num] = 2;

                if (backtrack(pos + 1))
                {
                    return true;
                }

                // Backtrack
                result[pos] = 0;
                used_count[num] = 1;
            }
        }
    }

    return false;
}

void solve(int test_n)
{
    n = test_n;
    result.assign(2 * n, 0);
    used_count.assign(n + 1, 0);
    first_pos.assign(n + 1, -1);

    backtrack(0);

    // Print result
    for (int i = 0; i < 2 * n; i++)
    {
        if (i > 0)
            cout << " ";
        cout << result[i];
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        solve(n);
    }

    return 0;
}