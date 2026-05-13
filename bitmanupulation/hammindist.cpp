class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int cnt = 0;

        while (x > 0 || y > 0)
        {
            int bitX = x & 1;
            int bitY = y & 1;

            if (bitX != bitY)
            {
                cnt++;
            }
            x >>= 1;
            y >>= 1;
        }

        return cnt;
    }
};