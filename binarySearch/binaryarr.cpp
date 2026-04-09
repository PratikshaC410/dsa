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
        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int blocks = 0;
        bool in_block = false;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1)
            {
                if (!in_block)
                {
                    blocks++;
                    in_block = true;
                }
            }
            else
            {
                in_block = false;
            }
        }

        bool starts_with_zero = (a[0] == 0);
        bool ends_with_zero = (a[n - 1] == 0);

        if (blocks % 2 == 1 && !(starts_with_zero && ends_with_zero))
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