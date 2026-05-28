#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    string target = "01032025";
    int target_ptr = 0;

    for (int i = 0; i < n; ++i)
    {
        char current_char = '0' + a[i];

        if (current_char == target[target_ptr])
        {
            target_ptr++;
        }

        if (target_ptr == 8)
        {
            cout << i + 1 << "\n"; // 1-based index of the step
            return;
        }
    }

    cout << 0 << "\n";
}

int main()
{
    // Fast I/O
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