//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        string substr = "";
        int largestSubstr = 0;

        for (int i = 0; i < n; i++)
        {
            substr += S1[i];

            if (S2.find(substr) != string::npos)
            {
                int length = substr.length();

                largestSubstr = max(largestSubstr, length);
            }
            else
            {
                substr.erase(0, 1);
            }
        }

        return largestSubstr;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends