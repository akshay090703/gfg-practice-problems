//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool isQueenSafe(vector<vector<int>> &board, int row, int col, int n)
    {
        // horizontal and vertical
        for (int i = 0; i < n; i++)
        {
            if (board[i][col] == 1 or board[row][i])
                return false;
        }

        // down-left
        int i = row, j = col;
        while (i >= 0 and j >= 0 and i < n and j < n)
        {
            if (board[i++][j--] == 1)
                return false;
        }

        // down-right
        i = row, j = col;
        while (i >= 0 and j >= 0 and i < n and j < n)
        {
            if (board[i++][j++] == 1)
                return false;
        }

        // up-left
        i = row, j = col;
        while (i >= 0 and j >= 0 and i < n and j < n)
        {
            if (board[i--][j--] == 1)
                return false;
        }

        // up-right
        i = row, j = col;
        while (i >= 0 and j >= 0 and i < n and j < n)
        {
            if (board[i--][j++] == 1)
                return false;
        }

        return true;
    }

    void solve(vector<vector<int>> &board, vector<vector<int>> &result, vector<int> &curr, int n, int row, int queens)
    {
        if (queens == 0)
        {
            result.push_back(curr);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (isQueenSafe(board, row, col, n))
            {
                curr[col] = row + 1;
                board[row][col] = 1;

                solve(board, result, curr, n, row + 1, queens - 1);

                curr[col] = 0;
                board[row][col] = 0;
            }
        }
    }

    vector<vector<int>> nQueen(int n)
    {
        vector<vector<int>> result;
        vector<int> rows(n);
        vector<vector<int>> board(n, vector<int>(n, 0));
        solve(board, result, rows, n, 0, n);

        sort(result.begin(), result.end());
        return result;
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

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends