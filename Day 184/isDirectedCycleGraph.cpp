//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool dfs(vector<int> adj[], vector<bool> &isVisited, vector<bool> &currPath, int currNode)
    {
        isVisited[currNode] = true;
        currPath[currNode] = true;

        for (auto neighbour : adj[currNode])
        {
            if (!isVisited[neighbour])
            {
                if (dfs(adj, isVisited, currPath, neighbour))
                    return true;
            }
            else if (currPath[neighbour])
                return true;
        }

        currPath[currNode] = false;
        return false;
    }

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<bool> isVisited(V, false);
        vector<bool> currPath(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!isVisited[i])
            {
                if (dfs(adj, isVisited, currPath, i))
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