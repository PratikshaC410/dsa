#include <iostream>
#include <string>
#include <algorithm>

class Solution
{
public:
    std::string mergeAlternately(std::string word1, std::string word2)
    {
        std::string merged = "";
        int n1 = word1.length();
        int n2 = word2.length();

        for (int i = 0; i < std::max(n1, n2); i++)
        {
            if (i < n1)
            {
                merged += word1[i];
            }
            if (i < n2)
            {
                merged += word2[i];
            }
        }

        return merged;
    }
};
