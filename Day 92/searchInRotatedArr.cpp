//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findPartition(int A[], int start, int end, int n)
    {
        int flag = A[0];

        while (start <= end)
        {
            int mid = start + ((end - start) / 2);

            if ((mid == 0 and A[mid] > A[mid + 1]) or (mid == n - 1 and A[mid] < A[mid - 1]))
            {
                return mid;
            }

            if (A[mid] < flag and A[mid - 1] > A[mid])
                return mid - 1;
            if (A[mid] > flag and A[mid] > A[mid + 1])
                return mid;

            if (A[mid] > flag)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return -1;
    }

    int search(int A[], int l, int h, int key)
    {
        int partition = findPartition(A, l, h, h + 1);

        if (partition == -1)
        {
            partition = h;
        }

        if (A[0] == key)
            return 0;

        if (A[0] < key)
        {
            h = partition;
        }
        else
        {
            l = partition + 1;
        }

        while (l <= h)
        {
            int mid = l + ((h - l) / 2);

            if (A[mid] < key)
            {
                l = mid + 1;
            }
            else if (A[mid] > key)
            {
                h = mid - 1;
            }
            else
            {
                return mid;
            }
        }

        return -1;
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
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
    return 0;
}
// } Driver Code Ends