#include <bits/stdc++.h>
using namespace std;

int digitSum(long long n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int countFriendly(long long x)
{
    int count = 0;

    for (int s = 1; s < 200; s++)
    {
        long long y = x + s;
        if (digitSum(y) == s)
        {
            count++;
        }
    }

    return count;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        long long x;
        cin >> x;
        cout << countFriendly(x) << "\n";
    }

    return 0;
}