//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // BFS Method
    // TC -> O(n + 2e)
    // SC -> O(n) + O(n)
    // bool isCycle(int V, vector<int> adj[]) {
    //     vector<bool> isVisited(V, false);
    //     queue<pair<int, int>> q;

    //     // because there could be multiple connected components
    //     for(int i = 0; i<V; i++) {
    //         if(!isVisited[i]) {
    //             q.push({i, -1});
    //             isVisited[i] = true;
    //             while(!q.empty()) {
    //                 int node = q.front().first;
    //                 int parent = q.front().second;
    //                 q.pop();

    //                 for(auto neighbour : adj[node]) {
    //                     if(!isVisited[neighbour]) {
    //                         isVisited[neighbour] = true;
    //                         q.push({neighbour, node});
    //                     } else if(isVisited[neighbour] and neighbour != parent) {
    //                         return true;
    //                     }
    //                 }
    //             }
    //         }
    //     }

    //     return false;
    // }

    bool containsCycleDFS(vector<int> adj[], vector<bool> &isVisited, int node, int parent)
    {
        isVisited[node] = true;

        for (auto neighbour : adj[node])
        {
            if (!isVisited[neighbour])
            {
                if (containsCycleDFS(adj, isVisited, neighbour, node))
                    return true;
            }
            else if (isVisited[neighbour] and neighbour != parent)
                return true;
        }

        return false;
    }

    // DFS Method
    // TC -> O(n + 2e) + O(n)
    // SC -> O(n) + O(n)
    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> isVisited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!isVisited[i])
            {
                if (containsCycleDFS(adj, isVisited, i, -1))
                    return true;
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
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends