// Given an array of integers nums sorted in non-decreasing order,
// find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.

#include <bits/stdc++.h>
class Solution
{
public:
    int firstOccurrence(vector<int> &v, int key)
    {
        int start = 0, end = v.size() - 1, res = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (v[mid] == key)
            {
                res = mid;
                end = mid - 1;
            }
            else if (key < v[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return res;
    }

    int lastOccurrence(vector<int> &v, int key)
    {
        int start = 0, end = v.size() - 1, res = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (v[mid] == key)
            {
                res = mid;
                start = mid + 1;
            }
            else if (key < v[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return res;
    }

    vector<int> searchRange(vector<int> &v, int key)
    {
        int first = firstOccurrence(v, key);
        int last = lastOccurrence(v, key);
        return {first, last};
    }
};
