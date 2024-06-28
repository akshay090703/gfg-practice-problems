#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        if (n != m)
            return false;

        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[s[i]]++;
            mp[t[i]]--;
        }

        for (auto pair : mp)
        {
            if (pair.second != 0)
                return false;
        }

        return true;
    }
};

int main()
{

    return 0;
}