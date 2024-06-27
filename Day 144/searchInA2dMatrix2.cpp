#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time Complexity -> O(n*log(m))
    // bool binarySearch(vector<int> &row, int target)
    // {
    //     int n = row.size();

    //     int start = 0, end = n - 1;
    //     while (start <= end)
    //     {
    //         int mid = start + ((end - start) / 2);

    //         if (row[mid] == target)
    //         {
    //             return true;
    //         }
    //         else if (row[mid] > target)
    //         {
    //             end = mid - 1;
    //         }
    //         else
    //         {
    //             start = mid + 1;
    //         }
    //     }

    //     return false;
    // }

    // bool searchMatrix(vector<vector<int>> &matrix, int target)
    // {
    //     int n = matrix.size();
    //     int m = matrix[0].size();

    //     if (target < matrix[0][0] or matrix[n - 1][m - 1] < target)
    //         return false;

    //     for (int i = 0; i < n; i++)
    //     {
    //         if (matrix[i][0] <= target and target <= matrix[i][m - 1])
    //         {
    //             bool ans = binarySearch(matrix[i], target);

    //             if (ans)
    //                 return true;
    //         }
    //     }

    //     return false;
    // }

    // Time Complexity -> O(n + m)
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        if (target < matrix[0][0] or matrix[n - 1][m - 1] < target)
            return false;

        int i = 0, j = m - 1;
        while (i < n and j >= 0)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            else if (matrix[i][j] < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        return false;
    }
};

int main()
{

    return 0;
}