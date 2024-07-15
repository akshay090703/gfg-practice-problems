//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool searchNext(vector<vector<char>> &board, int n, int m, string &word, int row, int col, int idx)
    {
        if (idx == word.length())
            return true;

        if (row < 0 or col < 0 or row >= n or col >= m or board[row][col] != word[idx] or board[row][col] == '!')
        {
            return false;
        }

        char ch = board[row][col];
        board[row][col] = '!';

        bool up = searchNext(board, n, m, word, row - 1, col, idx + 1);
        bool down = searchNext(board, n, m, word, row + 1, col, idx + 1);
        bool left = searchNext(board, n, m, word, row, col - 1, idx + 1);
        bool right = searchNext(board, n, m, word, row, col + 1, idx + 1);

        board[row][col] = ch;

        return up || down || left || right;
    }

    bool isWordExist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (searchNext(board, n, m, word, i, j, 0))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> board(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> board[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(board, word);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends