//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // // Using DFS
    // bool dfs(vector<int> adj[], vector<bool> &isVisited, vector<bool> &currPath, int currNode) {
    //     isVisited[currNode] = true;
    //     currPath[currNode] = true;

    //     for(auto neighbour : adj[currNode]) {
    //         if(!isVisited[neighbour]) {
    //             if(dfs(adj, isVisited, currPath, neighbour)) return true;
    //         } else if(currPath[neighbour]) return true;
    //     }

    //     currPath[currNode] = false;
    //     return false;
    // }

    // // Function to detect cycle in a directed graph.
    // bool isCyclic(int V, vector<int> adj[]) {
    //     vector<bool> isVisited(V, false);
    //     vector<bool> currPath(V, false);

    //     for(int i = 0; i<V; i++) {
    //         if(!isVisited[i]) {
    //             if(dfs(adj, isVisited, currPath, i)) return true;
    //         }
    //     }

    //     return false;
    // }

    // Using Kahn's algorithm(BFS)
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> inDegree(V, 0);
        for (int u = 0; u < V; u++)
        {
            for (int v = 0; v < adj[u].size(); v++)
            {
                inDegree[adj[u][v]]++;
            }
        }

        queue<int> q;
        vector<int> result;
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
                result.push_back(i);
            }
        }

        while (!q.empty())
        {
            int topNode = q.front();
            q.pop();

            for (auto neighbour : adj[topNode])
            {
                inDegree[neighbour]--;

                if (inDegree[neighbour] == 0)
                {
                    q.push(neighbour);
                    result.push_back(neighbour);
                }
            }
        }

        return result.size() != V;
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