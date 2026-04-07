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

        vector<string> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        string s = "";

        for (int i = 0; i < n; i++)
        {
            string prepend = a[i] + s;
            string append = s + a[i];

            if (prepend <= append)
            {
                s = prepend;
            }
            else
            {
                s = append;
            }
        }

        cout << s << "\n";
    }

    return 0;
}