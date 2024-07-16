//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool isColorSafe(unordered_map<int, vector<int>> &adjList, vector<int> &colored, int node, int color)
    {
        for (auto neighbour : adjList[node])
        {
            if (colored[neighbour] == color)
                return false;
        }

        return true;
    }

    bool solve(unordered_map<int, vector<int>> &adjList, int m, int n, vector<int> &colored, int node)
    {
        if (node == n)
            return true;

        for (int color = 1; color <= m; color++)
        {
            if (isColorSafe(adjList, colored, node, color))
            {
                colored[node] = color;

                if (solve(adjList, m, n, colored, node + 1))
                    return true;

                colored[node] = 0;
            }
        }

        return false;
    }

    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n)
    {
        unordered_map<int, vector<int>> adjList;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (graph[i][j] && i != j)
                {
                    adjList[i].push_back(j);
                }
            }
        }

        vector<int> colored(n, 0);
        return solve(adjList, m, n, colored, 0);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++)
        {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends