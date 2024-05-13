//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    string decodedString(string s)
    {
        stack<int> counts;
        stack<string> subStrs;

        int count = 0;
        string decoded = "";

        for (int i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]))
            {
                count = count * 10 + (s[i] - '0');
            }
            else if (s[i] == '[')
            {
                counts.push(count);
                count = 0;

                subStrs.push(decoded);
                decoded = "";
            }
            else if (s[i] == ']')
            {
                int multiples = counts.top();
                counts.pop();

                string temp = "";

                for (int i = 0; i < multiples; i++)
                {
                    temp += decoded;
                }

                decoded = subStrs.top() + temp;
                subStrs.pop();
            }
            else
            {
                decoded += s[i];
            }
        }

        return decoded;
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
        cout << ob.decodedString(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends