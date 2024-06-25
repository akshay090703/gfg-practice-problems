//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution
{
public:
    bool isAllocationPossible(int arr[], int n, int m, int maxPages)
    {
        int studentsAllocated = 1;
        long long sumOfPages = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > maxPages)
                return false;

            if (arr[i] + sumOfPages > maxPages)
            {
                studentsAllocated++;
                sumOfPages = arr[i];

                if (studentsAllocated > m)
                    return false;
            }
            else
            {
                sumOfPages += arr[i];
            }
        }

        return true;
    }

    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m)
    {
        if (m > n)
            return -1;

        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        long long res = -1;
        long long start = 0, end = sum;
        while (start <= end)
        {
            long long mid = start + ((end - start) / 2);

            if (isAllocationPossible(arr, n, m, mid))
            {
                end = mid - 1;
                res = mid;
            }
            else
            {
                start = mid + 1;
            }
        }

        return res;
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
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends