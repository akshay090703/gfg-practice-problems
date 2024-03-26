//{ Driver Code Starts
// C++ program to check if two strings are isomorphic

#include <bits/stdc++.h>

using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
public:
    // Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        int n = str1.length();
        int m = str2.length();

        if (n != m)
            return false;

        unordered_map<char, char> mapping1;
        unordered_map<char, char> mapping2;

        for (int i = 0; i < n; i++)
        {
            if (mapping1.find(str1[i]) == mapping1.end() and mapping2.find(str2[i]) == mapping2.end())
            {
                mapping1[str1[i]] = str2[i];
                mapping2[str2[i]] = str1[i];
            }
            else
            {
                if (mapping1[str1[i]] != str2[i] or mapping2[str2[i]] != str1[i])
                {
                    return false;
                }
            }
        }

        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin >> t;
    string s1, s2;
    while (t--)
    {
        cin >> s1;
        cin >> s2;
        Solution obj;
        cout << obj.areIsomorphic(s1, s2) << endl;
    }

    return 0;
}
// } Driver Code Ends