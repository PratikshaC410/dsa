#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> lastIndex;
    int maxLen = 0;
    int start = 0;

    for (int end = 0; end < s.size(); end++)
    {
        char c = s[end];

        if (lastIndex.find(c) != lastIndex.end() && lastIndex[c] >= start)
        {
            start = lastIndex[c] + 1;
        }

        lastIndex[c] = end;
        maxLen = max(maxLen, end - start + 1);
    }

    return maxLen;
}
