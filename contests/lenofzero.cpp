// <!-- You are given a binary array a of n elements, where each element is either 0 or 1. A clear segment is a group of consecutive elements consisting of only 0s.

// Your task is to find the length of the longest clear segment.

// Input Format

// The first line contains a single integer t - the number of test cases
// The first line of each test case contains a single integer n - the number of elements in the array.
// The second line of each test case contains n space-separated integers ai - each either 0 or 1.

// Constraints

// (1≤t≤1000)

// (1≤n≤100)

// (0≤ai≤1)
//  -->
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

        int maxLength = 0;
        int currentLength = 0;

        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;

            if (a == 0)
            {
                currentLength++;
                maxLength = max(maxLength, currentLength);
            }
            else
            {
                currentLength = 0;
            }
        }

        cout << maxLength << "\n";
    }

    return 0;
}