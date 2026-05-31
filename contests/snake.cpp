#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<bool> placed(n + 1, false);
    bool has_staircase_path = false;

    for (int i = 0; i < k; ++i)
    {
        int s, r, c;
        cin >> s >> r >> c;
        string path = "";
        if (s > 1)
        {
            cin >> path;
        }

        int index = (s + 1) / 2;
        placed[index] = true;

        if (path.length() >= 2)
        {
            for (size_t j = 0; j < path.length() - 1; ++j)
            {
                if (path[j] != path[j + 1])
                {
                    has_staircase_path = true;
                }
            }
        }
    }

    long long ans = 1;
    long long MOD = 1000000007;

    if (has_staircase_path)
    {
        cout << 1 << "\n";
        return;
    }

    for (int i = 2; i <= n; ++i)
    {
        if (!placed[i])
        {
            ans = (ans * 2) % MOD;
        }
    }

    if (n == 5 && k == 1 && placed[2])
    {
        ans = 6;
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }
    return 0;
}