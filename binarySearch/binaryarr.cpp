#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int zero_count = 0, one_count = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x == 0)
            {
                zero_count++;
            }
            else
            {
                one_count++;
            }
        }

        if (one_count >= zero_count)
        {
            cout << "Alice\n";
        }
        else
        {
            cout << "Bob\n";
        }
    }

    return 0;
}