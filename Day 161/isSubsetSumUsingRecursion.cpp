//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool solve(vector<int> &arr, int n, int k, int i, int sum)
    {
        if (sum > k)
            return false;

        if (i == n)
        {
            if (sum == k)
                return true;

            return false;
        }

        if (solve(arr, n, k, i + 1, sum + arr[i]))
            return true;

        if (solve(arr, n, k, i + 1, sum))
            return true;

        return false;
    }

    bool checkSubsequenceSum(int n, vector<int> &arr, int k)
    {
        return solve(arr, n, k, 0, 0);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr;

        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout << (ans ? "Yes" : "No") << "\n";
    }
    return 0;
}
// } Driver Code Ends