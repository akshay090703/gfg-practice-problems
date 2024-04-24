//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    void solve(vector<vector<int>> &m, int n, vector<string> &paths, map<char, pair<int, int>> &directions, vector<vector<bool>> &isVisited, int row, int col, string currPath)
    {
        if (row == n - 1 and col == n - 1)
        {
            paths.push_back(currPath);
            return;
        }

        for (auto dir : directions)
        {
            char curr = dir.first;
            int i = dir.second.first;
            int j = dir.second.second;

            int newRow = row + i;
            int newCol = col + j;

            if (newRow >= 0 and newRow < n and newCol >= 0 and newCol < n and m[newRow][newCol] == 1 and isVisited[newRow][newCol] == false)
            {
                isVisited[newRow][newCol] = true;
                solve(m, n, paths, directions, isVisited, newRow, newCol, currPath + curr);

                isVisited[newRow][newCol] = false;
            }
        }
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        map<char, pair<int, int>> directions = {
            {'D', {1, 0}},
            {'L', {0, -1}},
            {'R', {0, 1}},
            {'U', {-1, 0}},
        };

        vector<string> paths;

        if (m[0][0] != 1 or m[n - 1][n - 1] != 1)
            return paths;

        vector<vector<bool>> isVisited(n, vector<bool>(n, false));
        isVisited[0][0] = true;
        solve(m, n, paths, directions, isVisited, 0, 0, "");

        return paths;
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
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends