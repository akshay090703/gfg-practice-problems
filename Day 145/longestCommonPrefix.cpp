#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        sort(strs.begin(), strs.end());

        int n = strs.size();
        string firstStr = strs[0];
        string lastStr = strs[n - 1];

        string longestPrefix = "";
        int i = 0, j = 0;
        while (i < firstStr.size() and j < lastStr.size())
        {
            if (firstStr[i] != lastStr[j])
                break;
            longestPrefix += firstStr[i];

            i++;
            j++;
        }

        return longestPrefix;
    }
};

int main()
{

    return 0;
}