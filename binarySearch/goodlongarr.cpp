// Today, Sakurako was studying arrays. An array a
//  of length n
//  is considered good if and only if: the array a
//  is increasing, meaning ai−1<ai
//  for all 2≤i≤n
// the differences between adjacent elements are increasing, meaning ai−ai−1<ai+1−ai for all 2≤i<n
// Sakurako has come up with boundaries l
//  and r and wants to construct a good array of maximum length, where l≤ai≤r for all ai
// Help Sakurako find the maximum length of a good array for the given l and r
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long l, r;
        cin >> l >> r;

        long long d = r - l;

        long long k = (long long)((1 + sqrt(1 + 8.0 * d)) / 2);

        cout << k << '\n';
    }

    return 0;
}