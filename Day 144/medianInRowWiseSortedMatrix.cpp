//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int findUpperBound(vector<vector<int>> &matrix, int n, int m, int element)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int start = 0, end = m - 1;
            int smallestIdx = -1;
            while (start <= end)
            {
                int mid = start + ((end - start) / 2);

                if (matrix[i][mid] <= element)
                {
                    start = mid + 1;
                }
                else
                {
                    smallestIdx = mid;
                    end = mid - 1;
                }
            }

            count += (smallestIdx == -1 ? m : smallestIdx);
        }

        return count;
    }

    int median(vector<vector<int>> &matrix, int n, int m)
    {
        int size = n * m;
        int medianIdx = size / 2;

        int start = INT_MAX, end = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            start = min(start, matrix[i][0]);
            end = max(end, matrix[i][m - 1]);
        }

        while (start <= end)
        {
            int mid = start + ((end - start) / 2);
            int elementsSmaller = findUpperBound(matrix, n, m, mid);

            if (elementsSmaller <= medianIdx)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return start;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        int ans = -1;
        ans = obj.median(matrix, r, c);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends