//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9

// } Driver Code Ends
class Solution
{
public:
    vector<pair<pair<int, int>, pair<int, int>>> mapping = {
        {{0, 0}, {2, 2}},
        {{0, 3}, {2, 5}},
        {{0, 6}, {2, 8}},
        {{3, 0}, {5, 2}},
        {{3, 3}, {5, 5}},
        {{3, 6}, {5, 8}},
        {{6, 0}, {8, 2}},
        {{6, 3}, {8, 5}},
        {{6, 6}, {8, 8}},
    };

    bool isSafeNum(int grid[N][N], int row, int col, int num)
    {
        for (int i = 0; i < N; i++)
        {
            if (grid[row][i] == num or grid[i][col] == num)
                return false;
        }

        pair<int, int> start;
        pair<int, int> end;
        for (int i = 0; i < 9; i++)
        {
            start = mapping[i].first;
            end = mapping[i].second;

            if (start.first <= row and start.second <= col and end.first >= row and end.second >= col)
                break;
        }

        for (int i = start.first; i <= end.first; i++)
        {
            for (int j = start.second; j <= end.second; j++)
            {
                if (grid[i][j] == num)
                    return false;
            }
        }

        return true;
    }

    bool solve(int grid[N][N], vector<pair<int, int>> &emptySpaces, int idx)
    {
        if (idx == emptySpaces.size())
            return true;

        int row = emptySpaces[idx].first;
        int col = emptySpaces[idx].second;
        for (int i = 1; i <= 9; i++)
        {
            if (isSafeNum(grid, row, col, i))
            {
                grid[row][col] = i;

                if (solve(grid, emptySpaces, idx + 1))
                    return true;

                grid[row][col] = 0;
            }
        }

        return false;
    }

    // Function to find a solved Sudoku.
    bool SolveSudoku(int grid[N][N])
    {
        vector<pair<int, int>> emptySpaces;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j] == 0)
                {
                    emptySpaces.push_back({i, j});
                }
            }
        }

        return solve(grid, emptySpaces, 0);
    }

    // Function to print grids of the Sudoku.
    void printGrid(int grid[N][N])
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << grid[i][j] << " ";
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int grid[N][N];

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> grid[i][j];

        Solution ob;

        if (ob.SolveSudoku(grid) == true)
            ob.printGrid(grid);
        else
            cout << "No solution exists";

        cout << endl;
    }

    return 0;
}
// } Driver Code Ends