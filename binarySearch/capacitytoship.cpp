// A conveyor belt has packages that must be shipped from one port to another within days days.
// The ith package on the conveyor belt has a weight of weights[i].
// Each day, we load the ship with packages on the conveyor belt(in the order given by weights).
// We may not load more weight than the maximum weight capacity of the ship.
// Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

#include <bits/stdc++.h>

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int daysNeeded(vector<int> &weights, int capacity)
    {
        int days = 1;

        int currentLoad = 0;

        for (int w : weights)
        {
            if (currentLoad + w > capacity)
            {
                days++;

                currentLoad = w;
            }
            else
            {
                currentLoad += w;
            }
        }

        return days;
    }

    int shipWithinDays(vector<int> &weights, int d)
    {
        int left = *max_element(weights.begin(), weights.end());

        int right = accumulate(weights.begin(), weights.end(), 0);

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int needed = daysNeeded(weights, mid);

            if (needed <= d)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return left;
    }
};
