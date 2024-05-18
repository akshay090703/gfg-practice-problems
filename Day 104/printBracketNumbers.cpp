//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    vector<int> bracketNumbers(string s)
    {
        stack<int> brackets;
        vector<int> result;
        int num = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                num++;
                brackets.push(num);
                result.push_back(num);
            }
            else if (s[i] == ')')
            {
                if (brackets.empty())
                {
                    num++;
                    result.push_back(num);
                }
                else
                {
                    result.push_back(brackets.top());
                    brackets.pop();
                }
            }
        }

        return result;
    }
};

//{ Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);

        Solution ob;

        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends