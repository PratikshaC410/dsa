// There is an integer array nums sorted in ascending order (with distinct values).
// Prior to being passed to your function, nums is possibly left rotated
// at an unknown index k (1 <= k < nums.length)
// Given the array nums after the possible rotation and an integer target, return the index
// of target if it is in nums, or -1 if it is not in nums.
// You must write an algorithm with O(log n) runtime complexity.

#include <bits/stdc++.h>
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[low] <= target && nums[mid] >= target)
                high = mid - 1;
            else
                low = mid + 1;

            else
            {
                if (nums[high] >= target && nums[mid] <= target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
    }
};