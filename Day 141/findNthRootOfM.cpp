//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int power(int m, int n, int c)
    {
        long long int ans = 1;

        for (int i = 1; i <= n; i++)
        {
            ans *= m;
            if (ans > c)
                return INT_MAX;
        }

        return ans;
    }

    int NthRoot(int n, int m)
    {
        if (m == 1)
            return 1; // Handling edge case where m is 1
        long long int start = 1, end = m / n;

        while (start <= end)
        {
            long long int mid = start + ((end - start) / 2);
            long long int nthRoot = power(mid, n, m);

            if (nthRoot == m)
                return mid;

            if (nthRoot < m)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.NthRoot(n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends