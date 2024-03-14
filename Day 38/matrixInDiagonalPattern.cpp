//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
public:
    vector<int> matrixDiagonally(vector<vector<int>> &mat)
    {
        vector<int> result;
        int n = mat.size();

        bool upwards = true;

        for (int i = 0; i < (2 * n) - 1; i++)
        {
            int row;
            int col;

            if (upwards)
            {
                if (i < n)
                {
                    row = i;
                }
                else
                {
                    row = n - 1;
                }

                col = i - row;

                while (row >= 0 and col < n)
                {
                    result.push_back(mat[row][col]);
                    row--;
                    col++;
                }
            }
            else
            {
                if (i < n)
                {
                    row = 0;
                }
                else
                {
                    row = i - n + 1;
                }

                col = i - row;

                while (row < n and col >= 0)
                {
                    result.push_back(mat[row][col]);
                    row++;
                    col--;
                }
            }

            upwards = !upwards;
        }

        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        int k = 0;
        // cin>>k;
        cin >> n;
        vector<vector<int>> mat(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int> ans = obj.matrixDiagonally(mat);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
}
// } Driver Code Ends