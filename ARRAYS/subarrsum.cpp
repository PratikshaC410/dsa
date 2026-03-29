// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.
#include <bits/std++.h>
int subarraySum(const vector<int> &nums, int k)
{
    int count = 0;
    int prefix_sum = 0;
    unordered_map<int, int> prefix_map;
    prefix_map[0] = 1;

    for (int num : nums)
    {
        prefix_sum += num;
        int target = prefix_sum - k;

        if (prefix_map.count(target))
        {
            count += prefix_map[target];
        }

        prefix_map[prefix_sum]++;
    }

    return count;
}