class Solution
{
public:
    bool isPrime(int num)
    {
        if (num < 2)
            return false;
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    int sumOfPrimesInRange(int n)
    {
        int temp = n;
        long long r = 0;
        while (temp > 0)
        {
            r = r * 10 + (temp % 10);
            temp /= 10;
        }

        int L = min((long long)n, r);
        int R = max((long long)n, r);

        long long totalSum = 0;
        for (int i = L; i <= R; i++)
        {
            if (isPrime(i))
            {
                totalSum += i;
            }
        }

        return totalSum;
    }
};