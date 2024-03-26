//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to check if a string is Pangram or not.
    bool checkPangram(string s)
    {
        vector<bool> isVisited(26, false);
        int n = s.length();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (isalpha(s[i]))
            {
                char smallLetter = tolower(s[i]);

                if (!isVisited[smallLetter - 'a'])
                {
                    isVisited[smallLetter - 'a'] = true;
                    count++;
                }
            }
        }

        return (count == 26);
    }
};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--)
    {
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return (0);
}

// } Driver Code Ends