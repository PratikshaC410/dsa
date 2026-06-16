#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        // dp[i] will store the number of combinations that sum up to i
        // Using unsigned int to prevent potential overflow runtime errors during intermediate additions,
        // even though the final answer is guaranteed to fit in a 32-bit signed integer.
        vector<unsigned int> dp(target + 1, 0);

        // Base case
        dp[0] = 1;

        // Outer loop iterates through all target values from 1 to target
        for (int i = 1; i <= target; ++i)
        {
            // Inner loop checks every number in the given array
            for (int num : nums)
            {
                if (i >= num)
                {
                    dp[i] += dp[i - num];
                }
            }
        }

        return dp[target];
    }
};

int main()
{
    Solution solver;
    vector<int> nums = {1, 2, 3};
    int target = 4;

    cout << "Number of combinations: " << solver.combinationSum4(nums, target) << "\n";
    return 0;
}