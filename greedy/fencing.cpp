#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        long long n, w;
        cin >> n >> w;
        long long answer = n - (n / w);

        cout << answer << "\n";
    }

    return 0;
}