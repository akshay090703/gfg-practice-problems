//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int sumOfDigit(long long K)
    {
        int sod = 0;
        while (K)
        {
            sod += K % 10;
            K /= 10;
        }
        return sod;
    }

    long long int numberCount(long long int N, long long int K)
    {
        long long int low = K + 1;

        // No number lesser than or equal to K
        // can have the required value of difference
        // Hence, the lower limit for binary search is set to K+1
        long long int high = min(N, K + 90);

        // Max sum of digits for a 10-digit
        // decimal number = 90
        // Hence, the difference between (K+90) and
        // sumOfDigits(K+90) will definitely be >= K
        // Hence, the upper limit for binary search is K+90

        // Time complexity for this binary search is
        // constant as the difference between upper and
        // lower limits is capped at 89
        while (low <= high)
        {
            long long int mid = low + ((high - low) / 2);
            if (mid - sumOfDigit(mid) < K)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return (N - high);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, k;
        cin >> n >> k;
        Solution ob;
        cout << ob.numberCount(n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends