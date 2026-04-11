// A kangaroo is initially at position 0 on a number line. It performs exactly k jumps.
// For each jump:
// i) On the 1st,3rd,5th, … (odd-numbered jumps), the kangaroo jumps forward by a units.
// ii)On the 2nd, 4th,6th, … (even-numbered jumps), the kangaroo jumps backward by b units.
// For each query, determine the final position of the kangaroo after all k jumps.
// Input Format

// * The first line contains a single integer `t` - the number of queries.
// * Each of the next `t` lines contains one query.
// * Each query consists of three space-separated integers `a`, `b`, and `k` - representing the forward jump, backward jump, and the total number of jumps, respectively.
// Constraints
// (1≤t≤1000)
// (1≤a,b,k≤10^9)
// Output Format
// Print t integers. The i-th integer should be the answer for the i-th query.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long a, b, k;
        cin >> a >> b >> k;

        long long oddJumps = (k + 1) / 2;

        long long evenJumps = k / 2;

        long long position = oddJumps * a - evenJumps * b;

        cout << position << "\n";
    }

    return 0;
}