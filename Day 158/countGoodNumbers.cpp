#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const int MOD = 1000000007;

    long long myPow(long long base, long long expo)
    {
        if (expo == 0)
            return 1;
        if (expo == 1)
            return base % MOD;

        long long half = myPow(base, expo / 2) % MOD;
        long long result = (half * half) % MOD;

        if (expo % 2 == 1)
            result = (result * base) % MOD;

        return result % MOD;
    }

    int countGoodNumbers(long long n)
    {
        long long oddCount = (n + 1) / 2;
        long long evenCount = n / 2;

        long long oddHalf = myPow(5, oddCount) % MOD;
        long long evenHalf = myPow(4, evenCount) % MOD;

        return (oddHalf * evenHalf) % MOD;
    }
};

int main()
{

    return 0;
}