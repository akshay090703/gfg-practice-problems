//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int romanToDecimal(string &str)
    {
        unordered_map<char, int> mapping = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int n = str.length();
        int decimalVal = 0;

        for (int i = 0; i < n; i++)
        {
            if (i < n - 1 and mapping[str[i]] < mapping[str[i + 1]])
            {
                decimalVal -= mapping[str[i]];
            }
            else
            {
                decimalVal += mapping[str[i]];
            }
        }

        return decimalVal;
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
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends