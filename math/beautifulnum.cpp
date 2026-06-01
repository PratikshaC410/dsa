#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    string x;
    cin >> x;

    long long digit_sum = 0;
    vector<int> decreases; // Stores how much we can decrease the sum by changing each digit

    for (int i = 0; i < x.length(); i++)
    {
        int digit = x[i] - '0';
        digit_sum += digit;

        if (i == 0)
        {
            // The first digit cannot be 0, so the maximum we can decrease it is to 1
            decreases.push_back(max(0, digit - 1));
        }
        else
        {
            // Other digits can be turned into 0, so we can decrease by the full digit value
            decreases.push_back(digit);
        }
    }

    // If it's already beautiful, 0 moves
    if (digit_sum <= 9)
    {
        cout << 0 << "\n";
        return;
    }

    sort(decreases.rbegin(), decreases.rend());

    int moves = 0;
    for (int dec : decreases)
    {
        digit_sum -= dec;
        moves++;
        if (digit_sum <= 9)
        {
            break;
        }
    }

    cout << moves << "\n";
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