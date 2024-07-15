#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string &s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
                return false;
        }

        return true;
    }

    void solve(string &s, vector<vector<string>> &result, vector<string> &curr, int idx)
    {
        if (idx == s.length())
        {
            result.push_back(curr);
            return;
        }

        for (int i = idx; i < s.length(); i++)
        {
            if (isPalindrome(s, idx, i))
            {
                curr.push_back(s.substr(idx, i - idx + 1));
                solve(s, result, curr, i + 1);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string &s)
    {
        vector<vector<string>> result;
        vector<string> curr;
        solve(s, result, curr, 0);

        return result;
    }
};

int main()
{

    return 0;
}