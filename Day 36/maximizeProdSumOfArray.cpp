//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    const long long MOD = 1000000007;

    int Maximize(int a[], int n)
    {
        sort(a, a + n);

        // Initialize result to store the maximum value
        long long result = 0;

        // Calculate the maximum value using the rearranged array
        for (int i = 0; i < n; ++i)
        {
            result = (result + (long long)a[i] * i);
        }

        return result % MOD;
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
        cout << ob.Maximize(a, n) << endl;
    }
}
// } Driver Code Ends