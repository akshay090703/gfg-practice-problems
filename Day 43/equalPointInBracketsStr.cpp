//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int findIndex(string str)
    {
        int n = str.length();

        int openingBrackets = 0, closingBrackets = 0;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == ')')
            {
                closingBrackets++;
            }
        }

        if (closingBrackets == 0)
            return 0;

        for (int i = 0; i < n; i++)
        {
            if (str[i] == ')')
            {
                closingBrackets--;
            }
            else
            {
                openingBrackets++;
            }

            if (openingBrackets == closingBrackets)
                return i + 1;
        }

        if (openingBrackets == 0)
            return n;

        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.findIndex(s) << endl;
    }
}
// } Driver Code Ends