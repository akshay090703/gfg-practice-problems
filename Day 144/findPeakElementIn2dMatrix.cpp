#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxElementInRow(vector<vector<int>> &mat, int n, int m, int row)
    {
        int maxEl = INT_MIN;
        int idx = -1;
        for (int i = 0; i < m; i++)
        {
            if (mat[row][i] > maxEl)
            {
                maxEl = mat[row][i];
                idx = i;
            }
        }

        return idx;
    }

    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        int start = 0, end = n - 1;
        while (start <= end)
        {
            int mid = start + ((end - start) / 2);
            int maxIdx = maxElementInRow(mat, n, m, mid);
            int maxEl = mat[mid][maxIdx];

            int topEl = INT_MIN;
            int bottomEl = INT_MIN;

            if (mid > 0)
                topEl = mat[mid - 1][maxIdx];
            if (mid < n - 1)
                bottomEl = mat[mid + 1][maxIdx];

            if (maxEl > topEl and maxEl > bottomEl)
            {
                return {mid, maxIdx};
            }
            else if (maxEl < topEl)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return {-1, -1};
    }
};

int main()
{

    return 0;
}