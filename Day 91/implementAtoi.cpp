//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    bool feasible(string s)
    {
        if (s[0] != '-' and !isdigit(s[0]))
        {
            return false;
        }

        for (int i = 1; i < s.length(); i++)
        {
            if (!isdigit(s[i]))
            {
                return false;
            }
        }

        return true;
    }

    /*You are required to complete this method */
    int atoi(string s)
    {
        if (feasible(s))
        {
            bool negative = false;

            if (s[0] == '-')
            {
                negative = true;
                s = s.substr(1, s.length() - 1);
            }

            int result = stoi(s);
            if (negative)
                result *= -1;

            return result;
        }

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
        int ans = ob.atoi(s);
        cout << ans << endl;
    }
}
// } Driver Code Ends