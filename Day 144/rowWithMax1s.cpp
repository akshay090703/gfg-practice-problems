//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int binarySearch(vector<vector<int>> &arr, int i, int m)
    {
        int start = 0, end = m - 1;
        int idx = -1;
        while (start <= end)
        {
            int mid = start + ((end - start) / 2);

            if (arr[i][mid] == 1)
            {
                end = mid - 1;
                idx = mid;
            }
            else
            {
                start = mid + 1;
            }
        }

        if (idx == -1)
            return 0;

        return (m - idx);
    }

    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        int maxIdx = -1;
        int maxCount = 0;
        for (int i = 0; i < n; i++)
        {
            int count = binarySearch(arr, i, m);

            if (count > maxCount)
            {
                maxCount = count;
                maxIdx = i;
            }
        }

        return maxIdx;
    }

    // EVEN MORE OPTIMIZED APPROACH
    // int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    // {
    //     int maxIdx = -1;

    //     int i = 0, j = m - 1;
    //     while (i < n and j >= 0)
    //     {
    //         if (arr[i][j] == 1)
    //         {
    //             j--;
    //             maxIdx = i;
    //         }
    //         else
    //         {
    //             i++;
    //         }
    //     }

    //     return maxIdx;
    // }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends