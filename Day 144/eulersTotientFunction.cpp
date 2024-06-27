//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // function to find totient of n
    long long ETF(long long n)
    {
        long long result = n;

        for (int p = 2; p * p <= n; p++)
        {
            if (n % p == 0)
            {
                while (n % p == 0)
                {
                    n /= p;
                }

                // using floating point division
                result *= (1.0 - (1.0 / p));
            }
        }

        if (n > 1)
        {
            result -= (result / n);
        }

        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.ETF(N) << endl;
    }
    return 0;
}
// } Driver Code Ends