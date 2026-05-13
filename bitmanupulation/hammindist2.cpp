class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        // XOR gives 1 where bits are different
        int diff = x ^ y;
        int cnt = 0;

        // Count the number of set bits (1s) in the result
        while (diff > 0)
        {
            cnt += (diff & 1); // Add 1 if the last bit is set
            diff >>= 1;        // Shift right to check the next bit
        }

        return cnt;
    }
};