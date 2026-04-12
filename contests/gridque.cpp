// King Fumble Bean of Blunderland built a Puzzle Mansion where every minister owns a uniquely coloured rectangular chamber with sides parallel to the mansion walls. Each chamber forms a solid contiguous rectangle in the grid. Any minister whose chamber shares a side of positive length with the King's chamber holds the title of Royal Minister.
// The King wants to register all his Royal Ministers in the Royal Ledger.
// Help the King find the count!
// Input Format
// The first line contains two space-separated integers n, m - the number of rows and columns of the mansion - and an uppercase letter c - the colour of the King's chamber.
// The following n lines contain m characters each, describing the mansion layou
// Constraints
// 1 ≤ n, m ≤ 100
// Uppercase Latin letters A–Z represent chamber colours; each colour is unique
// '.' stands for an empty chamber
// Output Format
// Print a single integer - the count of Royal Ministers.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    char c;
    cin >> n >> m >> c;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    bool seen[26] = {false};

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == c)
            {
                for (int d = 0; d < 4; d++)
                {
                    int ni = i + dx[d];
                    int nj = j + dy[d];

                    if (ni >= 0 && ni < n && nj >= 0 && nj < m)
                    {
                        char neighbor = grid[ni][nj];

                        if (neighbor != '.' && neighbor != c)
                        {
                            seen[neighbor - 'A'] = true;
                        }
                    }
                }
            }
        }
    }

    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        if (seen[i])
            count++;
    }

    cout << count << endl;

    return 0;
}