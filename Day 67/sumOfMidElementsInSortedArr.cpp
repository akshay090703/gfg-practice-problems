//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int findMidSum(int ar1[], int ar2[], int n)
    {
        int total = n + 1;
        int i = 0, j = 0;
        int mid1 = 0, mid2 = 0;

        while (total--)
        {
            mid2 = mid1;

            if ((i < n and j < n and ar1[i] <= ar2[j]) or j == n)
            {
                mid1 = ar1[i++];
            }
            else
            {
                mid1 = ar2[j++];
            }
        }

        return mid1 + mid2;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++)
        {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++)
        {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends