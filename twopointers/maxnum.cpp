#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<int> maxNumber(std::vector<int> &nums1, std::vector<int> &nums2, int k)
    {
        int m = nums1.size();
        int n = nums2.size();
        std::vector<int> maxResult;

        // Iterate through all valid number of elements we can take from nums1
        int start = std::max(0, k - n);
        int end = std::min(k, m);

        for (int i = start; i <= end; ++i)
        {
            std::vector<int> sub1 = maxArray(nums1, i);
            std::vector<int> sub2 = maxArray(nums2, k - i);
            std::vector<int> merged = merge(sub1, sub2);

            if (maxResult.empty() || merged > maxResult)
            {
                maxResult = merged;
            }
        }

        return maxResult;
    }

private:
    // Helper 1: Find the max number of length x from a single array
    std::vector<int> maxArray(const std::vector<int> &nums, int x)
    {
        std::vector<int> res;
        int drop = nums.size() - x; // How many elements we are allowed to drop

        for (int num : nums)
        {
            while (drop > 0 && !res.empty() && res.back() < num)
            {
                res.pop_back();
                drop--;
            }
            res.push_back(num);
        }

        // Ensure the size is exactly x
        res.resize(x);
        return res;
    }

    // Helper 2: Merge two arrays to create the lexicographically largest combination
    std::vector<int> merge(const std::vector<int> &sub1, const std::vector<int> &sub2)
    {
        std::vector<int> res;
        auto it1 = sub1.begin();
        auto it2 = sub2.begin();

        while (it1 != sub1.end() || it2 != sub2.end())
        {
            // std::lexicographical_compare / vector comparison handles look-ahead automatically
            if (std::vector<int>(it1, sub1.end()) > std::vector<int>(it2, sub2.end()))
            {
                res.push_back(*it1);
                it1++;
            }
            else
            {
                res.push_back(*it2);
                it2++;
            }
        }
        return res;
    }
};