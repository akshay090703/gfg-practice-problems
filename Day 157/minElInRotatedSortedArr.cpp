//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findMin(int arr[], int n)
    {
        int firstEl = arr[0];
        int res = -1;

        int start = 0, end = n - 1;
        while (start <= end)
        {
            int mid = start + ((end - start) / 2);

            if (arr[mid] >= firstEl)
            {
                start = mid + 1;
            }
            else
            {
                res = mid;
                end = mid - 1;
            }
        }

        if (res == -1)
            return arr[0];

        return arr[res];
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
        int i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.findMin(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends