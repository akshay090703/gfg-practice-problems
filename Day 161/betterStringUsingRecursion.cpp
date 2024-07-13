//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void solve(string &str, string curr, unordered_set<string> &s, int i)
    {
        if (i == str.length())
        {
            s.insert(curr);
            return;
        }

        solve(str, curr, s, i + 1);
        solve(str, curr + str[i], s, i + 1);
    }

    string betterString(string str1, string str2)
    {
        unordered_set<string> s1;
        unordered_set<string> s2;

        solve(str1, "", s1, 0);
        solve(str2, "", s2, 0);

        if (s1.size() >= s2.size())
            return str1;

        return str2;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends