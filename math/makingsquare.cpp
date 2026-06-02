#include <bits/stdc++.h>
using namespace std;

// Each rect (l, b): width = l, height = b. Rotation forbidden — no swapping.
bool check(int d[3][2])
{
    int idx[3] = {0, 1, 2};
    do
    {
        int l0 = d[idx[0]][0], b0 = d[idx[0]][1];
        int l1 = d[idx[1]][0], b1 = d[idx[1]][1];
        int l2 = d[idx[2]][0], b2 = d[idx[2]][1];

        // Layout 1: column — same width S, heights sum to S
        if (l0 == l1 && l1 == l2 && b0 + b1 + b2 == l0)
            return true;

        // Layout 2: row — same height S, widths sum to S
        if (b0 == b1 && b1 == b2 && l0 + l1 + l2 == b0)
            return true;

        // Layout 3: rect[0] on top (full width S=l0), rect[1]+rect[2] side by side below
        // l1+l2==S, same height b1==b2, total height b0+b1==S
        if (l1 + l2 == l0 && b1 == b2 && b0 + b1 == l0)
            return true;

        // Layout 4: rect[0] on left (full height S=b0), rect[1]+rect[2] stacked on right
        // b1+b2==S, same width l1==l2, total width l0+l1==S
        if (b1 + b2 == b0 && l1 == l2 && l0 + l1 == b0)
            return true;

    } while (next_permutation(idx, idx + 3));

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int dims[3][2];
        for (int i = 0; i < 3; i++)
            cin >> dims[i][0] >> dims[i][1];
        cout << (check(dims) ? "YES" : "NO") << "\n";
    }
    return 0;
}