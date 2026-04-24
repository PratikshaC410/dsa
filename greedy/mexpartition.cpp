#include <iostream>
#include <map>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> counts;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        counts[x]++;
    }
    if (counts[0] == 0)
    {
        cout << 0 << endl;
    }
    else if (counts[1] < counts[0])
    {
        cout << 1 << endl;
    }
    else
    {
        int missing = 2;
        while (counts[missing] > 0)
        {
            missing++;
        }
        cout << missing << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}