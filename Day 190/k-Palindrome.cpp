//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool is_k_palin(string s, int k);

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int k;
        cin >> k;

        cout << is_k_palin(s, k) << endl;
    }
    return 0;
}
// } Driver Code Ends

/*You are required to complete this function*/

int solve(string &s, int i, int j, vector<vector<int>> &dp)
{
    if (i == j)
        return 1;
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == s[j])
    {
        return dp[i][j] = 2 + solve(s, i + 1, j - 1, dp);
    }

    return dp[i][j] = max(solve(s, i + 1, j, dp), solve(s, i, j - 1, dp));
}

bool is_k_palin(string s, int k)
{
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int lps = solve(s, 0, n - 1, dp);
    return (n - lps) <= k;
}