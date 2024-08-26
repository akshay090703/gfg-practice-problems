//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    const int MOD = 1e9 + 7;

    // long long solve(int n, vector<long long> &dp) {
    //     if(n == 0) return 1;

    //     if(dp[n] != -1) return dp[n];

    //     long long oneStep = 0, twoStep = 0, threeStep = 0;

    //     if(n - 1 >= 0) oneStep = solve(n - 1, dp);
    //     if(n - 2 >= 0) twoStep = solve(n - 2, dp);
    //     if(n - 3 >= 0) threeStep = solve(n - 3, dp);

    //     return dp[n] = (oneStep + twoStep + threeStep) % MOD;
    // }

    // long long solve(int n) {
    //     vector<long long> dp(n + 1, 0);
    //     dp[0] = 1;

    //     for(int i = 1; i<=n; i++) {
    //         long long oneStep = 0, twoStep = 0, threeStep = 0;

    //         if(i - 1 >= 0) oneStep = dp[i - 1];
    //         if(i - 2 >= 0) twoStep = dp[i - 2];
    //         if(i - 3 >= 0) threeStep = dp[i - 3];

    //         dp[i] = (oneStep + twoStep + threeStep) % MOD;
    //     }

    //     return dp[n];
    // }

    long long solve(int n)
    {
        long long last = 1;
        long long lastLast = 0;
        long long lastLastLast = 0;

        for (int i = 1; i <= n; i++)
        {
            long long oneStep = 0, twoStep = 0, threeStep = 0;

            if (i - 1 >= 0)
                oneStep = last;
            if (i - 2 >= 0)
                twoStep = lastLast;
            if (i - 3 >= 0)
                threeStep = lastLastLast;

            lastLastLast = lastLast;
            lastLast = last;
            last = (oneStep + twoStep + threeStep) % MOD;
        }

        return last;
    }

    // Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        // vector<long long> dp(n + 1, -1);
        // return solve(n, dp);

        return solve(n);
    }
};

//{ Driver Code Starts.
int main()
{
    // taking testcases
    int t;
    cin >> t;

    while (t--)
    {
        // taking number of steps in stair
        int n;
        cin >> n;
        Solution ob;
        // calling function countWays()
        cout << ob.countWays(n) << endl;
    }

    return 0;
}

// } Driver Code Ends