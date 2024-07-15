//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool isPalindrome(string &str, int start, int end)
    {
        while (start <= end)
        {
            if (str[start++] != str[end--])
                return false;
        }

        return true;
    }

    void solve(string &str, vector<string> &curr, int idx, int &minCuts, int cuts)
    {
        if (idx == str.length())
        {
            minCuts = min(minCuts, cuts - 1);
            return;
        }

        for (int i = idx; i < str.length(); i++)
        {
            if (isPalindrome(str, idx, i))
            {
                curr.push_back(str.substr(idx, i - idx + 1));
                solve(str, curr, i + 1, minCuts, cuts + 1);
                curr.pop_back();
            }
        }
    }

    int palindromicPartition(string str)
    {
        vector<string> curr;
        int minCuts = INT_MAX;
        solve(str, curr, 0, minCuts, 0);

        return minCuts;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
}
// } Driver Code Ends