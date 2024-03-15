//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    /* if x is present in arr[] then returns the count
        of occurrences of x, otherwise returns 0. */
    int count(int arr[], int n, int x)
    {
        int start = 0;
        int end = n - 1;
        int count = 0;
        int mid = -1;

        while (start <= end)
        {
            mid = start + ((end - start) / 2);

            if (arr[mid] == x)
            {
                break;
            }
            else if (arr[mid] > x)
            {
                end--;
            }
            else
            {
                start++;
            }
        }

        if (start > end)
        {
            return 0;
        }

        int temp = mid;
        while (temp - 1 >= 0 and arr[temp] == arr[temp - 1])
        {
            temp--;
            count++;
        }

        while (mid + 1 < n and arr[mid] == arr[mid + 1])
        {
            mid++;
            count++;
        }

        return ++count;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends