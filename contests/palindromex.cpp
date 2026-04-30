#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(2 * n);
    vector<vector<int>> pos(n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }

    int max_mex = 1;

    int L = pos[0][0], R = pos[0][1];
    int current_k = 1;

    while (current_k < n)
    {
        bool center_found = false;
        // Can current_k be a center for the mirrored 0...current_k-1?
        // This requires 0...current_k-1 to be mirrored relative to one pos of current_k
        int p1 = pos[current_k][0];
        int p2 = pos[current_k][1];

        // Logic: If 0...current_k-1 are mirrored around p1, MEX is current_k + 1
        // (Checking mirroring requires tracking the L and R of the mirrored block)

        // Simple case from image: if both 0s surround a 1, MEX is 2.
        // If both 0s and both 1s surround a 2, MEX is 3.

        // For the sake of this placement prep, the core logic is:
        // MEX = K if (0...K-2) are nested and (K-1) is in the middle.

        // This loop would verify the nesting property for each increasing MEX.
        break;
    }
}