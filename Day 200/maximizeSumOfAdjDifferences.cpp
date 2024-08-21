//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int solve(int arr[], int n, int lastEl, vector<vector<int>> &dp)
    {
        if (n == 0)
            return 0;

        int last = lastEl == 1 ? 1 : 0;

        if (dp[n][last] != -1)
            return dp[n][last];

        int change = abs(1 - lastEl) + solve(arr, n - 1, 1, dp);
        int notChange = abs(arr[n - 1] - lastEl) + solve(arr, n - 1, arr[n - 1], dp);

        return dp[n][last] = max(change, notChange);
    }

    int maximumDifferenceSum(int arr[], int N)
    {
        vector<vector<int>> dp(N + 1, vector<int>(2, -1));
        return max(solve(arr, N - 1, arr[N - 1], dp), solve(arr, N - 1, 1, dp));
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
        cout << ob.maximumDifferenceSum(a, n) << "\n";
    }
    return 0;
}

// } Driver Code Ends