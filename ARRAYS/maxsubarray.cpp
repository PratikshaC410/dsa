// Given an integer array nums, find the subarray with the largest sum, and return its sum.
class Solution
{
public:
    int maxSubArray(vector<int> &a)
    {
        int maxi = INT_MIN, sum = 0, n = a.size();
        int maxele = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            maxele = max(maxele, a[i]);
            sum += a[i];
            if (sum < 0)
                sum = 0;
            maxi = max(sum, maxi);
        }

        if (maxi == 0)
            return maxele;
        return maxi;
    }
};