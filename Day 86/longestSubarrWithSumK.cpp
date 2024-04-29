//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int lenOfLongSubarr(int A[], int N, int K)
    {
        // sum : i
        unordered_map<int, int> sumMap;
        int sum = 0;
        int longestSubarr = 0;

        for (int i = 0; i < N; i++)
        {
            sum += A[i];

            if (sum == K)
            {
                longestSubarr = i + 1;
            }
            else if (sumMap.find(sum - K) != sumMap.end())
            {
                longestSubarr = max(longestSubarr, abs(sumMap[sum - K] - i));
            }

            if (sumMap.find(sum) == sumMap.end())
            {
                sumMap[sum] = i;
            }
        }

        return longestSubarr;
    }
};

//{ Driver Code Starts.

int main()
{
    // code

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.lenOfLongSubarr(a, n, k) << endl;
    }

    return 0;
}
// } Driver Code Ends