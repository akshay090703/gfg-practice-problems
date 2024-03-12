//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    const int MOD = 1000000007;

    int solve(int n, vector<long long> &memo)
    {
        if (n == 0 or n == 1)
        {
            return n;
        }

        if (memo[n] != -1)
        {
            return memo[n];
        }

        memo[n] = (solve(n - 1, memo) + solve(n - 2, memo)) % MOD;

        return memo[n];
    }

    int nthFibonacci(int n)
    {
        vector<long long> memo(n + 1, -1);
        return solve(n, memo);
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
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends