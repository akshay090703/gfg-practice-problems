//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {
        vector<int> ans;
        int left = 0;
        int right = c - 1;
        int top = 0;
        int bottom = r - 1;
        int direction = 0;

        while (left <= right and top <= bottom)
        {
            // left to right
            if (direction % 4 == 0)
            {
                for (int i = left; i <= right; i++)
                {
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }

            // top to bottom
            if (direction % 4 == 1)
            {
                for (int i = top; i <= bottom; i++)
                {
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }

            // right to left
            if (direction % 4 == 2)
            {
                for (int i = right; i >= left; i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // bottom to top
            if (direction % 4 == 3)
            {
                for (int i = bottom; i >= top; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }

            direction++;
        }

        return ans;
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
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends