#include <vector>
#include <algorithm>

class Solution
{
public:
    int minimumTotal(std::vector<std::vector<int>> &triangle)
    {
        int n = triangle.size();

        // Initialize DP array with the values of the bottom row
        std::vector<int> dp = triangle[n - 1];

        // Walk bottom-up starting from the second-to-last row
        for (int r = n - 2; r >= 0; --r)
        {
            for (int c = 0; c <= r; ++c)
            {
                // The min path to the current cell is its own value
                // plus the minimum of the two adjacent choices below it
                dp[c] = triangle[r][c] + std::min(dp[c], dp[c + 1]);
            }
        }

        // The top of the triangle now holds the minimum path sum
        return dp[0];
    }
};