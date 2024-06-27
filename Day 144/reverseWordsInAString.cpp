#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.length();
        string result = "";
        string temp = "";

        for (int i = 0; i < n; i++)
        {
            if (s[i] != ' ')
            {
                temp += s[i];
            }
            else
            {
                if (temp != "")
                {
                    if (result != "")
                        result = temp + " " + result;
                    else
                        result = temp;

                    temp = "";
                }
            }
        }

        if (temp != "")
        {
            if (result != "")
                result = temp + " " + result;
            else
                result = temp;
        }

        return result;
    }
};

int main()
{

    return 0;
}