#include <iostream>
#include <algorithm>

using namespace std;

bool check(int d[3][2])
{
    int idx[3] = {0, 1, 2};
    do
    {
        int a = d[idx[0]][0], b = d[idx[0]][1];
        int c = d[idx[1]][0], D = d[idx[1]][1];
        int e = d[idx[2]][0], f = d[idx[2]][1];

        // Layout 1: All 3 in a parallel strip (Column or Row)
        if (b == D && D == f && a + c + e == b)
            return true;
        if (a == c && c == e && b + D + f == a)
            return true;

        // Layout 2: rect[0] takes full side of length 'a'
        int rem_a = a - b;
        if (rem_a > 0)
        {
            // Option A: rect[1] and rect[2] are side-by-side inside leftover
            if (c + e == a && D == rem_a && f == rem_a)
                return true;
            if (c + f == a && D == rem_a && e == rem_a)
                return true;
            if (D + e == a && c == rem_a && f == rem_a)
                return true;
            if (D + f == a && c == rem_a && e == rem_a)
                return true;

            // Option B: rect[1] and rect[2] are stacked vertically inside leftover
            if (c == a && e == a && D + f == rem_a)
                return true;
            if (c == a && f == a && D + e == rem_a)
                return true;
            if (D == a && e == a && c + f == rem_a)
                return true;
            if (D == a && f == a && c + e == rem_a)
                return true;
        }

        // Layout 2: rect[0] takes full side of length 'b'
        int rem_b = b - a;
        if (rem_b > 0)
        {
            // Option A: rect[1] and rect[2] are side-by-side inside leftover
            if (c + e == b && D == rem_b && f == rem_b)
                return true;
            if (c + f == b && D == rem_b && e == rem_b)
                return true;
            if (D + e == b && c == rem_b && f == rem_b)
                return true;
            if (D + f == b && c == rem_b && e == rem_b)
                return true;

            // Option B: rect[1] and rect[2] are stacked vertically inside leftover
            if (c == b && e == b && D + f == rem_b)
                return true;
            if (c == b && f == b && D + e == rem_b)
                return true;
            if (D == b && e == b && c + f == rem_b)
                return true;
            if (D == b && f == b && c + e == rem_b)
                return true;
        }

    } while (next_permutation(idx, idx + 3));

    return false;
}

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int dims[3][2];
        for (int i = 0; i < 3; i++)
        {
            cin >> dims[i][0] >> dims[i][1];
        }
        cout << (check(dims) ? "YES" : "NO") << "\n";
    }
    return 0;
}