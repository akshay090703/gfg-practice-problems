#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };

        int n = s.length();
        int result = 0;
        int lastVal = INT_MIN;
        for (int i = n - 1; i >= 0; i--)
        {
            int curr_val = mp[s[i]];

            if (lastVal <= curr_val)
            {
                result += curr_val;
            }
            else
            {
                result -= curr_val;
            }

            lastVal = curr_val;
        }

        return result;
    }
};

int main()
{

    return 0;
}