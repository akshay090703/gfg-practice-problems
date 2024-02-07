#include <iostream>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(string arr[], int n)
    {
        string ans = "";
        for (int i = 0; i < arr[0].length(); i++)
        {
            char ch = arr[0][i];

            bool match = true;

            for (int j = 1; j < n; j++)
            {
                if (arr[j].size() < i || ch != arr[j][i])
                {
                    match = false;
                    break;
                }
            }

            if (!match)
                break;
            else
            {
                ans.push_back(ch);
            }
        }

        if (ans.length() == 0)
        {
            ans = "-1";
        }

        return ans;
    }
};

int main()
{

    return 0;
}