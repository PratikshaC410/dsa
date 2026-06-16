#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        // An arithmetic subarray must have at least 3 elements
        if (n < 3)
            return 0;

        int total_count = 0;
        int current_count = 0;

        // Start from index 2 because we need to check the previous two elements
        for (int i = 2; i < n; ++i)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
            {
                // If it extends the arithmetic sequence, increment consecutive count
                current_count++;
                total_count += current_count;
            }
            else
            {
                // If the chain breaks, reset the consecutive count
                current_count = 0;
            }
        }

        return total_count;
    }
};

int main()
{
    Solution solver;
    vector<int> nums = {1, 2, 3, 4, 5};

    cout << "Number of arithmetic subarrays: " << solver.numberOfArithmeticSlices(nums) << "\n";
    return 0;
}