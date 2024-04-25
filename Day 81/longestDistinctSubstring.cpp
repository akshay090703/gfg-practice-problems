//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars(string S);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;

        cout << longestSubstrDistinctChars(S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends

int longestSubstrDistinctChars(string S)
{
    int n = S.length();
    int longestStr = INT_MIN;
    string currStr = "";

    for (int i = 0; i < n; i++)
    {
        while (currStr.find(S[i]) != string::npos)
        {
            currStr.erase(0, 1);
        }

        currStr += S[i];
        int length = currStr.length();
        longestStr = max(longestStr, length);
    }

    return longestStr;
}