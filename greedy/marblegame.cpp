#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    map<int, int> counts;
    for (int i = 0; i < n; ++i)
    {
        int c;
        cin >> c;
        counts[c]++;
    }

    vector<int> moves;
    for (auto const &[color, count] : counts)
    {
        if (count == 1)
        {
            moves.push_back(2);
        }
        else
        {
            moves.push_back(1);
            moves.push_back(1);
        }
    }

    sort(moves.rbegin(), moves.rend());

    int alice_score = 0;
    for (size_t i = 0; i < moves.size(); ++i)
    {
        if (i % 2 == 0)
        { // Aliceturn
            alice_score += moves[i];
        }
    }

    cout << alice_score << "\n";
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