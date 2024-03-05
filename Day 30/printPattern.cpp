//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void solve(vector<int> &ans, int &temp, int n, bool isDecreasing)
    {
        if (isDecreasing and temp <= 0)
        {
            solve(ans, temp, n, false);
            return;
        }

        ans.push_back(temp);

        if (!isDecreasing and temp >= n)
        {
            return;
        }

        if (isDecreasing)
        {
            temp -= 5;
        }
        else
        {
            temp += 5;
        }

        if (temp <= n)
        {
            solve(ans, temp, n, isDecreasing);
        }
    }

    vector<int> pattern(int N)
    {
        vector<int> ans;
        int temp = N;

        solve(ans, temp, N, true);

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        Solution ob;
        vector<int> ans = ob.pattern(N);
        for (int u : ans)
            cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends