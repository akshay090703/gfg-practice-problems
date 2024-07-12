#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<string> &result, int open, int close, int max, string curr)
    {
        if (2 * max == curr.length())
        {
            result.push_back(curr);
            return;
        }

        if (open < max)
        {
            solve(result, open + 1, close, max, curr + "(");
        }

        if (close < open)
        {
            solve(result, open, close + 1, max, curr + ")");
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        solve(result, 0, 0, n, "");

        return result;
    }
};

int main()
{

    return 0;
}