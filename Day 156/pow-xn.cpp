#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double solve(double x, int n)
    {
        if (n == 0)
        {
            return 1.00;
        }

        double half = solve(x, n / 2);
        if (n % 2 == 1)
        {
            return x * half * half;
        }
        else
        {
            return half * half;
        }
    }

    double myPow(double x, int n)
    {
        if (x > 1 and n == INT_MIN)
            return 0.00;

        double sol = solve(x, abs(n));

        if (n < 0)
        {
            return 1.00 / sol;
        }

        return sol;
    }
};

int main()
{

    return 0;
}