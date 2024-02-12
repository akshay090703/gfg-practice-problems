#include <iostream>
using namespace std;

class Solution
{
public:
    const long long MOD = 1000000007;

    long long sequence(int n)
    {
        long long num = 1;
        long long sum = 0;

        for (long long i = 0; i < n; i++)
        {
            long long prod = 1;

            for (long long j = 0; j <= i; j++)
            {
                prod = (prod * num) % MOD;
                num = (num + 1) % MOD;
            }

            sum = (sum + prod) % MOD;
        }

        return sum;
    }
};

int main()
{

    return 0;
}