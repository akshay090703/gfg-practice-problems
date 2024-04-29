//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    bool isCelebrity(vector<vector<int>> &M, int n, int celebrity)
    {
        for (int i = 0; i < n; i++)
        {
            if (i == celebrity)
                continue;

            if (M[i][celebrity] == 0)
            {
                return false;
            }
        }

        return true;
    }

    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            bool celebrity = true;
            for (int j = 0; j < n; j++)
            {
                if (M[i][j] == 1)
                {
                    celebrity = false;
                    break;
                }
            }

            if (celebrity)
            {
                st.push(i);
                break;
            };
        }

        if (!st.empty())
        {
            if (isCelebrity(M, n, st.top()))
            {
                return st.top();
            }
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
        int n;
        cin >> n;
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
}

// } Driver Code Ends