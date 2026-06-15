class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int N = m + n - 2;
        int K = std::min(m - 1, n - 1);

        long long ans = 1;

        for (int i = 1; i <= K; ++i)
        {
            ans = ans * (N - K + i) / i;
        }

        return static_cast<int>(ans);
    }
};