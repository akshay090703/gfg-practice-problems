#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(string &s, int i, int sign, long long num, bool &isNum, bool &isSign, bool &isSpace)
    {
        if (i == s.length())
        {
            return static_cast<int>(sign * num);
        }

        char ch = s[i];

        if (ch == ' ' and num == 0 and sign == 1 and !isNum and isSpace)
        {
            return solve(s, i + 1, sign, num, isNum, isSign, isSpace);
        }

        if (num == 0 and !isNum and (ch == '-' or ch == '+') and !isSign and isSpace)
        {
            isSign = true;
            isSpace = false;
            sign = ch == '-' ? -1 : 1;
            return solve(s, i + 1, sign, num, isNum, isSign, isSpace);
        }

        if (isdigit(ch))
        {
            isNum = true;
            num = (num * 10) + (ch - '0');

            if (num * sign > INT_MAX)
            {
                return INT_MAX;
            }
            else if (num * sign < INT_MIN)
            {
                return INT_MIN;
            }

            return solve(s, i + 1, sign, num, isNum, isSign, isSpace);
        }

        return static_cast<int>(num * sign);
    }

    int myAtoi(string s)
    {
        bool isSign = false;
        bool isNum = false;
        bool isSpace = true;
        return solve(s, 0, 1, 0, isNum, isSign, isSpace);
    }
};

int main()
{

    return 0;
}