//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // dist : node : parent
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        vector<pair<int, int>> mst;
        vector<bool> isVisited(V, false);

        minHeap.push({0, {0, -1}});
        int mstSum = 0;
        while (!minHeap.empty())
        {
            int dist = minHeap.top().first;
            int node = minHeap.top().second.first;
            int parent = minHeap.top().second.second;
            minHeap.pop();

            if (isVisited[node])
                continue;

            isVisited[node] = true;

            if (parent != -1)
            {
                mst.push_back({parent, node});
                mstSum += dist;
            }

            for (auto neighbour : adj[node])
            {
                int v = neighbour[0];
                int wt = neighbour[1];

                if (!isVisited[v])
                    minHeap.push({wt, {v, node}});
            }
        }

        return mstSum;
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
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends