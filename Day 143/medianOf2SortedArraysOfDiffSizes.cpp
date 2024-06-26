//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int> &array1, vector<int> &array2);

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    double MedianOfArrays(vector<int> &array1, vector<int> &array2)
    {
        int n1 = array1.size();
        int n2 = array2.size();
        int n = n1 + n2;

        if (n1 > n2)
            return MedianOfArrays(array2, array1);

        int left = (n + 1) / 2;
        int start = 0, end = n1;
        while (start <= end)
        {
            int mid1 = (start + end) >> 1;
            int mid2 = left - mid1;

            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;

            // because of 0-based indexing
            if (mid1 > 0)
                l1 = array1[mid1 - 1];
            if (mid2 > 0)
                l2 = array2[mid2 - 1];
            if (mid1 < n1)
                r1 = array1[mid1];
            if (mid2 < n2)
                r2 = array2[mid2];

            if (l1 <= r2 and l2 <= r1)
            {
                if (n % 2 == 1)
                {
                    return (long double)max(l1, l2);
                }

                return (long double)((max(l1, l2) + min(r1, r2)) / 2.0);
            }
            else if (l1 > r2)
            {
                end = mid1 - 1;
            }
            else
            {
                start = mid1 + 1;
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
        int m, n;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> array1[i];
        }
        cin >> n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> array2[i];
        }
        Solution ob;
        cout << ob.MedianOfArrays(array1, array2) << endl;
    }
    return 0;
}

// } Driver Code Ends