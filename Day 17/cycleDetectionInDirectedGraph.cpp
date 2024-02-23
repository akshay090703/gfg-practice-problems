//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool dfs(vector<int> adj[], vector<bool> &isVisited, vector<bool> &dfsVisited, int node)
    {
        if (isVisited[node] and dfsVisited[node])
        {
            return true;
        }
        else if (!isVisited[node])
        {
            isVisited[node] = true;
            dfsVisited[node] = true;

            for (auto neighbour : adj[node])
            {
                if (dfs(adj, isVisited, dfsVisited, neighbour))
                {
                    return true;
                }
            }
        }
        dfsVisited[node] = false; // backtrack

        return false;
    }

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<bool> isVisited(V);
        vector<bool> dfsVisited(V);

        for (int i = 0; i < V; i++)
        {
            if (dfs(adj, isVisited, dfsVisited, i))
            {
                return true;
            }
        }

        return false;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends