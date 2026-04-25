class Solution
{
public:
    vector<int> nextLargerElement(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> result(n);
        stack<int> s;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && s.top() <= arr[i])
            {
                s.pop();
            }

            if (s.empty())
            {
                result[i] = -1;
            }
            else
            {
                result[i] = s.top();
            }

            s.push(arr[i]);
        }
        return result;
    }
};