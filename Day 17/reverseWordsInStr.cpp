//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to reverse words in a given string.
    string reverseWords(string S)
    {
        string ans = "";
        string currStr = "";
        int i = 0;
        int n = S.length();

        while (i < n)
        {
            while (i < n and S[i] != '.')
            {
                currStr += S[i];
                i++;
            }

            if (i < n)
            {
                currStr = S[i] + currStr;
            }

            ans = currStr + ans;
            currStr = "";
            i++;
        }

        return ans;
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
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends