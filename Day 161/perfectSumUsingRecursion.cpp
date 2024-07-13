//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    const int MOD = 1000000007;

    int solve(int arr[], int sum, int i, int target, int n)
    {
        if (sum > target)
            return 0;

        if (i == n)
        {
            if (sum == target)
                return 1;

            return 0;
        }

        int l = solve(arr, sum + arr[i], i + 1, target, n) % MOD;

        int r = solve(arr, sum, i + 1, target, n) % MOD;

        return (l + r) % MOD;
    }

    int perfectSum(int arr[], int n, int sum)
    {
        return solve(arr, 0, 0, sum, n);
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.perfectSum(a, n, sum) << "\n";
    }
    return 0;
}

// } Driver Code Ends