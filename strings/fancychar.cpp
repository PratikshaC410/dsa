class Solution
{
public:
    string makeFancyString(string s)
    {
        if (s.length() < 3)
        {
            return s;
        }

        std::string result = "";

        for (char c : s)
        {
            int n = result.length();

            // Check if the current character matches the last two in the result
            if (n >= 2 && result[n - 1] == c && result[n - 2] == c)
            {
                continue; // Skip this character
            }

            result += c;
        }

        return result;
    }
};