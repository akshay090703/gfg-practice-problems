//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        vector<vector<int>> adjList(N);
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        queue<pair<int, int>> q;
        vector<bool> isVisited(N, false);
        vector<int> dist(N, -1);

        isVisited[src] = true;
        q.push({src, 0});
        while (!q.empty())
        {
            int node = q.front().first;
            int distance = q.front().second;
            q.pop();

            if (dist[node] == -1)
                dist[node] = distance;
            else
                dist[node] = min(dist[node], distance);

            for (auto neighbour : adjList[node])
            {
                if (!isVisited[neighbour])
                {
                    isVisited[neighbour] = true;
                    q.push({neighbour, distance + 1});
                }
            }
        }

        return dist;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 2; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends