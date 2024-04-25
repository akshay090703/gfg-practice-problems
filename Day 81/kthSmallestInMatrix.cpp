//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> mat[i][j];
        int r;
        cin >> r;
        cout << kthSmallest(mat, n, r) << endl;
    }
    // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
    return 0;
}

// } Driver Code Ends

struct Compare
{
    bool operator()(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b)
    {
        // for increasing order
        return a.first > b.first;
    }
};

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare> minHeap;

    for (int i = 0; i < n; i++)
    {
        minHeap.push({mat[i][0], {i, 0}});
    }

    for (int i = 0; i < k - 1; i++)
    {
        auto top = minHeap.top();
        minHeap.pop();

        int row = top.second.first;
        int col = top.second.second;

        if (col < n - 1)
        {
            minHeap.push({mat[row][col + 1], {row, col + 1}});
        }
    }

    return minHeap.top().first;
}
