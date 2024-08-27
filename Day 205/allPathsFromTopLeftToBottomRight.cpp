//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    const int MOD = 1e9 + 7;

    long long int solve(int row, int col, vector<vector<int>> &dp)
    {
        if (row == 0 and col == 0)
            return 1;
        if (row < 0 or col < 0)
            return 0;

        if (dp[row][col] != -1)
            return dp[row][col];

        int up = solve(row - 1, col, dp) % MOD;
        int left = solve(row, col - 1, dp) % MOD;

        return dp[row][col] = (up + left) % MOD;
    }

    long long int solve(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 and j == 0)
                    continue;

                int up = 0;
                if (i - 1 >= 0)
                    up = dp[i - 1][j] % MOD;

                int left = 0;
                if (j - 1 >= 0)
                    left = dp[i][j - 1] % MOD;

                dp[i][j] = (up + left) % MOD;
            }
        }

        return dp[m - 1][n - 1];
    }

    long long int numberOfPaths(int m, int n)
    {
        // vector<vector<int>> dp(m, vector<int> (n, -1));
        // return solve(m - 1, n - 1, dp);

        return solve(m, n);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout << ob.numberOfPaths(m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends