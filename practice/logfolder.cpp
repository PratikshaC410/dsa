class Solution
{
public:
    int minOperations(vector<string> &logs)
    {

        int cnt = 0;
        for (int c = 0; c <= logs.size() - 1; c++)
        {
            if (logs[c] == "../")
            {
                if (cnt != 0)
                    cnt = cnt - 1;
            }
            else if (logs[c] == "./")
            {
                continue;
            }
            else
            {
                cnt = cnt + 1;
            }
        }

        return cnt;
    }
};