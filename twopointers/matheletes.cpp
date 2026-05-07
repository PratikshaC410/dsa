#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    sort(x.begin(), x.end());

    int score = 0;
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int sum = x[left] + x[right];
        if (sum == k)
        {
            score++;
            left++;
            right--;
        }
        else if (sum < k)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    cout << score << endl;
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