#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        if (n != m)
            return false;

        char mapping_s[256] = {0};
        char mapping_t[256] = {0};
        for (int i = 0; i < n; i++)
        {
            char c1 = s[i];
            char c2 = t[i];

            if (mapping_s[c1] == 0 and mapping_t[c2] == 0)
            {
                mapping_s[c1] = c2;
                mapping_t[c2] = c1;
            }
            else if (mapping_s[c1] != c2 or mapping_t[c2] != c1)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{

    return 0;
}