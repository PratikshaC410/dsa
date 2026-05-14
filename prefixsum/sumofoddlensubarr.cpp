#include <vector>

class Solution
{
public:
    int sumOddLengthSubarrays(std::vector<int> &arr)
    {
        int totalSum = 0;
        int n = arr.size();

        for (int i = 0; i < n; ++i)
        {
            long totalAppearances = (i + 1) * (n - i);

            long oddAppearances = (totalAppearances + 1) / 2;

            totalSum += oddAppearances * arr[i];
        }

        return totalSum;
    }
};