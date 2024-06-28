#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int n = s.length();

        int i = 0;
        while (i < n and s[i] == ' ')
            i++;

        int sign = 1;
        if (i < n and (s[i] == '-' or s[i] == '+'))
        {
            if (s[i] == '-')
            {
                sign = -1;
            }

            i++;
        }

        long long result = 0;
        while (i < n and isdigit(s[i]))
        {
            int digit = s[i] - '0';
            result = result * 10 + digit;

            if (result * sign >= INT_MAX)
                return INT_MAX;
            if (result * sign <= INT_MIN)
                return INT_MIN;

            i++;
        }

        return result * sign;
    }
};

int main()
{

    return 0;
}