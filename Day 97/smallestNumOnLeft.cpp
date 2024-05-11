//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> leftSmaller(int n, int a[])
    {
        vector<int> result;
        result.push_back(-1);

        stack<int> st;
        st.push(a[0]);

        int mini = a[0];

        for (int i = 1; i < n; i++)
        {
            if (mini >= a[i])
            {
                result.push_back(-1);
                mini = a[i];

                st.push(a[i]);
                continue;
            }

            while (!st.empty() and st.top() >= a[i])
            {
                st.pop();
            }

            result.push_back(st.top());
            st.push(a[i]);
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
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends