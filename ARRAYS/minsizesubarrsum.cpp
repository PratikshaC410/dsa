#include <bits/stdc++.h>
int slidingWindow(vector<int> &nums, int target)
{
    int left = 0, sum = 0, result = INT_MAX;

    for (int right = 0; right < nums.size(); right++)
    {
        sum += nums[right];

        while (sum >= target)
        {
            result = min(result, right - left + 1);
            sum -= nums[left++];
        }
    }

    return result == INT_MAX ? 0 : result;
}