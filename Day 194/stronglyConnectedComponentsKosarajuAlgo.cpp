//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    void dfs1(vector<vector<int>> &adj, vector<bool> &isVisited, stack<int> &st, int node)
    {
        isVisited[node] = true;

        for (auto neighbour : adj[node])
        {
            if (!isVisited[neighbour])
            {
                dfs1(adj, isVisited, st, neighbour);
            }
        }

        st.push(node);
    }

    void dfs2(vector<vector<int>> &revAdj, vector<bool> &isVisited, int node)
    {
        isVisited[node] = true;

        for (auto neighbour : revAdj[node])
        {
            if (!isVisited[neighbour])
            {
                dfs2(revAdj, isVisited, neighbour);
            }
        }
    }

    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        stack<int> finishingNodes;
        vector<bool> isVisited(V, false);

        // Step 1: Sorting all nodes in terms of finishing time
        for (int i = 0; i < V; i++)
        {
            if (!isVisited[i])
            {
                dfs1(adj, isVisited, finishingNodes, i);
            }
        }

        // Step 2: Reversing the graph
        vector<vector<int>> revAdj(V);
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                int v = adj[i][j];

                revAdj[v].push_back(i);
            }
        }

        // Step 3: DFSing the reversed graph and calculating the SCCs
        // The number of DFS calls will be equal to the number of SCCs
        fill(isVisited.begin(), isVisited.end(), false);
        int scc = 0;
        while (!finishingNodes.empty())
        {
            int node = finishingNodes.top();
            finishingNodes.pop();

            if (!isVisited[node])
            {
                dfs2(revAdj, isVisited, node);
                scc++;
            }
        }

        return scc;
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

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends