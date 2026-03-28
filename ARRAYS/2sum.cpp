// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<pair<int, int>> numswithindx;
        for (int i = 0; i < n; i++)
        {
            numswithindx.push_back({nums[i], i});
        }
        sort(numswithindx.begin(), numswithindx.end());
        int l = 0;
        , r = n - 1;
        while (l <= r)
        {
            int sum = numswithindx[l].first + numswithindx[r].first;
            if (sum == target)
            {
                return {numswithindx[l].second, numswithindx[r].second};
            }
            else if (sum < target)
                l++;
            else
                r++;
        }
        return {-1, -1};
    }
};