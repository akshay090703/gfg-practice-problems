//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int binarySearch(vector<int> &mat, int start, int end)
    {
        int maxCount = end + 1;
        while (start <= end)
        {
            int mid = start + ((end - start) / 2);
            if (mat[mid] == 1 and mat[mid - 1] == 1)
            {
                end = mid - 1;
            }
            else if (mat[mid] == 0)
            {
                start = mid + 1;
            }
            else
            {
                return maxCount - mid; // count
            }
        }

        return 0;
    }

    int maxOnes(vector<vector<int>> &Mat, int N, int M)
    {
        if (N == 0 or M == 0)
            return 0;

        int max_count = INT_MIN;
        int idx = -1;
        for (int i = 0; i < N; i++)
        {
            int curr_count = binarySearch(Mat[i], 0, M - 1);
            // cout<< curr_count << " ";

            if (max_count < curr_count)
            {
                idx = i;
                max_count = curr_count;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}
// } Driver Code Ends