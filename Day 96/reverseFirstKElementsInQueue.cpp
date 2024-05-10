//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k)
    {
        int n = q.size();

        if (k > q.size())
        {
            k = k % n;
        }

        stack<int> st;
        for (int i = 0; i < k; i++)
        {
            st.push(q.front());
            q.pop();
        }

        while (!st.empty())
        {
            q.push(st.top());
            st.pop();
        }

        queue<int> temp;
        for (int i = 0; i < n - k; i++)
        {
            temp.push(q.front());
            q.pop();
        }

        while (!temp.empty())
        {
            q.push(temp.front());
            temp.pop();
        }

        return q;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0)
        {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty())
        {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends