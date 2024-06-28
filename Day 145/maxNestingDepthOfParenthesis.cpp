#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int n = s.length();
        int balance = 0;
        int max_depth = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                balance++;
                max_depth = max(max_depth, balance);
            }
            else if (s[i] == ')')
            {
                balance--;
            }
        }

        return max_depth;
    }
};

int main()
{

    return 0;
}