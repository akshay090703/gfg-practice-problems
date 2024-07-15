//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    int solve(string &s, unordered_set<string> &wordSet, int idx)
    {
        if (idx == s.length())
        {
            return 1;
        }

        for (int i = idx; i < s.length(); i++)
        {
            if (wordSet.find(s.substr(idx, i - idx + 1)) != wordSet.end())
            {
                if (solve(s, wordSet, i + 1))
                {
                    return 1;
                }
            }
        }

        return 0;
    }

    int wordBreak(int n, string s, vector<string> &dictionary)
    {
        unordered_set<string> wordSet(dictionary.begin(), dictionary.end());
        return solve(s, wordSet, 0);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> dictionary;
        for (int i = 0; i < n; i++)
        {
            string S;
            cin >> S;
            dictionary.push_back(S);
        }
        string s;
        cin >> s;
        Solution ob;
        cout << ob.wordBreak(n, s, dictionary) << "\n";
    }
}

// } Driver Code Ends