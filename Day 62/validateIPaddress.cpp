//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution
{
public:
    int isValid(string s)
    {
        int n = s.length();
        int i = 0;
        int portions = 0;
        int dots = 0;

        while (i < n)
        {
            int zeroes = 0;
            int portionLen = 0;
            string num = "";

            while (i < n and s[i] != '.')
            {
                if (s[i] >= '0' and s[i] <= '9')
                {
                    if (zeroes > 0)
                        return false;

                    if (s[i] == '0')
                        zeroes++;

                    if (portionLen > 3)
                    {
                        return false;
                    }

                    num += s[i];
                    portionLen++;
                    i++;
                }
                else
                {
                    return false;
                }
            }

            if (i < n and s[i] == '.')
                dots++;

            portions++;

            if (num == "")
                return false;

            if (stoi(num) > 255)
                return false;
            i++;
        }

        if (portions != 4 or dots != 3)
            return false;

        return true;
    }
};

//{ Driver Code Starts.

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends