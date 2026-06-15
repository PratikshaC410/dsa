class Solution
{
public:
    int minPathSum(std::vector<std::vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == 0 && j == 0)
                    continue;

                if (i == 0)
                {
                    grid[i][j] += grid[i][j - 1]; // Can only come from left
                }
                else if (j == 0)
                {
                    grid[i][j] += grid[i - 1][j]; // Can only come from above
                }
                else
                {
                    grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);
                }
            }
        }
        return grid[m - 1][n - 1];
    }
};