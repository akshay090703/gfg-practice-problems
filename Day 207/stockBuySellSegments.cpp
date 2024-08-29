//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int solve(vector<int> &A, int n, int i, bool libertyToBuy, vector<vector<int>> &dp)
    {
        if (i == n)
        {
            return 0;
        }

        if (dp[i][libertyToBuy] != -1)
            return dp[i][libertyToBuy];

        int profit = 0;
        if (libertyToBuy)
        {
            int buy = -A[i] + solve(A, n, i + 1, false, dp);
            int notBuy = 0 + solve(A, n, i + 1, true, dp);

            profit = max(buy, notBuy);
        }
        else
        {
            int sell = +A[i] + solve(A, n, i + 1, true, dp);
            int notSell = 0 + solve(A, n, i + 1, false, dp);

            profit = max(sell, notSell);
        }

        return dp[i][libertyToBuy] = profit;
    }

    vector<vector<int>> solve(vector<int> &A, int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int day = 0; day <= 1; day++)
            {
                int profit = 0;

                if (day)
                {
                    int buy = -A[i] + dp[i + 1][0];
                    int notBuy = 0 + dp[i + 1][1];

                    profit = max(buy, notBuy);
                }
                else
                {
                    int sell = A[i] + dp[i + 1][1];
                    int notSell = 0 + dp[i + 1][0];

                    profit = max(sell, notSell);
                }

                dp[i][day] = profit;
            }
        }

        // return dp[0][1];
        return dp;
    }

    // Function to find the days of buying and selling stock for max profit.
    vector<vector<int>> stockBuySell(vector<int> A, int n)
    {
        // vector<vector<int>> dp(n, vector<int> (2, -1));
        // solve(A, n, 0, true, dp);

        vector<vector<int>> dp = solve(A, n);

        vector<vector<int>> result;
        int i = 0;
        while (i < n)
        {
            if (dp[i][1] = -A[i] + dp[i + 1][0])
            {
                int buyDay = i;

                while (i < n and dp[i][0] != A[i] + dp[i + 1][1])
                {
                    i++;
                }

                if (i < n and buyDay != i)
                {
                    int sellDay = i;
                    result.push_back({buyDay, sellDay});
                    // cout << buyDay << " " << sellDay << endl;
                }
            }

            i++;
        }

        return result;
    }
};

//{ Driver Code Starts.

int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for (int i = 0; i < ans.size(); i++)
        c += A[ans[i][1]] - A[ans[i][0]];
    return (c == p) ? 1 : 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> A[i];
        }
        Solution ob;
        vector<vector<int>> ans = ob.stockBuySell(A, n);
        int p = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int x = A[i + 1] - A[i];
            if (x > 0)
                p += x;
        }
        if (ans.size() == 0)
            cout << "No Profit";
        else
        {
            cout << check(ans, A, p);
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends