//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    const int MOD = 1000000007;

    // #define ll long long
    ll countStrings(int n)
    {
        ll endsWithZero = 1;
        ll endsWithOne = 1;
        ll sum = 2;

        if (n == 1)
            return sum;

        for (int i = 2; i <= n; i++)
        {
            endsWithOne = endsWithZero % MOD;
            endsWithZero = sum % MOD;
            sum = (endsWithOne + endsWithZero) % MOD;
        }

        return sum % MOD;
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
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends