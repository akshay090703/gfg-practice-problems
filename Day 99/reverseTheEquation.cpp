//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string reverseEqn(string s)
    {
        string num = "";
        stack<string> equation;

        for (int i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]))
            {
                num += s[i];
            }
            else
            {
                equation.push(num);
                num = "";

                // count, character
                equation.push(string(1, s[i]));
            }
        }

        if (num != "")
        {
            equation.push(num);
        }

        string result = "";
        while (!equation.empty())
        {
            result += equation.top();

            equation.pop();
        }

        return result;
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
        cout << ob.reverseEqn(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends