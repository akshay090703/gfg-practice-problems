//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++
class Solution
{
public:
    int findMaxLen(string s)
    {
        stack<int> st;
        st.push(-1);

        int longestSubstr = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();

                if (st.empty())
                {
                    st.push(i);
                }
                else
                {
                    longestSubstr = max(longestSubstr, i - st.top());
                }
            }
        }

        return longestSubstr;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends