#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int l, a, b;
        cin >> l >> a >> b;

        int maxPrize = a;
        int current = a;

        for (int spin = 1; spin < l; spin++)
        {
            current = (current + b) % l;
            maxPrize = max(maxPrize, current);
        }

        cout << maxPrize << "\n";
    }

    return 0;
}