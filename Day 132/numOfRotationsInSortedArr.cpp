//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int findKRotation(int arr[], int n)
    {
        int start = 0;
        int end = n - 1;
        int minEl = INT_MAX;
        int idx = -1;

        while (start <= end)
        {
            int mid = start + ((end - start) / 2);

            if (arr[start] <= arr[end])
            {
                if (arr[start] < minEl)
                {
                    minEl = arr[start];
                    idx = start;
                }

                break;
            }

            if (arr[start] <= arr[mid])
            {
                if (arr[start] < minEl)
                {
                    minEl = arr[start];
                    idx = start;
                }

                start = mid + 1;
            }
            else
            {
                if (arr[mid] < minEl)
                {
                    minEl = arr[mid];
                    idx = mid;
                }

                end = mid - 1;
            }
        }

        return idx;
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
        int a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends