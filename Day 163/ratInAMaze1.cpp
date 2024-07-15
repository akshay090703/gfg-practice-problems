//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    unordered_map<char, pair<int, int>> directions = {
        {'U', {-1, 0}}, {'D', {1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}};

    bool isValidPath(vector<vector<int>> &m, int n, vector<vector<bool>> &isVisited, int row, int col)
    {
        return (row >= 0 and col >= 0 and row < n and col < n and !isVisited[row][col] and m[row][col] == 1);
    }

    void solve(vector<vector<int>> &m, int n, vector<string> &result, vector<vector<bool>> &isVisited, int row, int col, string &path)
    {
        if (row == n - 1 and col == n - 1)
        {
            result.push_back(path);
            return;
        }

        for (auto p : directions)
        {
            char d = p.first;
            int r = p.second.first;
            int c = p.second.second;

            int newRow = row + r;
            int newCol = col + c;

            if (isValidPath(m, n, isVisited, newRow, newCol))
            {
                path.push_back(d);
                isVisited[newRow][newCol] = true;

                solve(m, n, result, isVisited, newRow, newCol, path);

                path.pop_back();
                isVisited[newRow][newCol] = false;
            }
        }
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        if (m[0][0] == 0 or m[n - 1][n - 1] == 0)
            return {"-1"};

        vector<string> result;
        vector<vector<bool>> isVisited(n, vector<bool>(n, false));
        isVisited[0][0] = true;
        string path = "";

        solve(m, n, result, isVisited, 0, 0, path);

        if (result.empty())
            return {"-1"};
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