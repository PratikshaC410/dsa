#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int compareStrings(string s1, string s2)
{
    unordered_map<string, int> priority;
    vector<string> order = {
        "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "ng",
        "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

    for (int i = 0; i < order.size(); i++)
    {
        priority[order[i]] = i;
    }

    int i = 0, j = 0;
    while (i < s1.length() && j < s2.length())
    {
        string token1, token2;

        if (i + 1 < s1.length() && s1[i] == 'n' && s1[i + 1] == 'g')
        {
            token1 = "ng";
            i += 2;
        }
        else
        {
            token1 = string(1, s1[i]);
            i += 1;
        }

        if (j + 1 < s2.length() && s2[j] == 'n' && s2[j + 1] == 'g')
        {
            token2 = "ng";
            j += 2;
        }
        else
        {
            token2 = string(1, s2[j]);
            j += 1;
        }

        if (priority[token1] < priority[token2])
            return -1;
        if (priority[token1] > priority[token2])
            return 1;
    }

    if (i < s1.length())
        return 1; // s1 has remaining characters
    if (j < s2.length())
        return -1; // s2 has remaining characters

    return 0; // Both equal
}