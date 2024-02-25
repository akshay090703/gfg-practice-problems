//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int smallestSubWithSum(int arr[], int n, int x)
    {
        int sum = 0;
        int count = INT_MAX;

        int start = 0;

        for (int end = 0; end < n; end++)
        {
            sum += arr[end];

            while (sum > x)
            {
                count = min(count, end - start + 1); // to update the count

                sum -= arr[start];
                start++;
            }
        }

        if (count == INT_MAX)
        {
            return 0;
        }

        return count;
    }
};

//{ Driver Code Starts.

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.smallestSubWithSum(a, n, x) << endl;
    }
    return 0;
}
// } Driver Code Ends