//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.

    // Using Priority Queue
    // TC -> E*(logV)
    // vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    // {
    //     vector<vector<pair<int, int>>> adjList(V);
    //     for(int i = 0; i<V; i++) {
    //         int u = i;

    //         for(int j = 0; j<adj[i].size(); j++) {
    //             int v = adj[i][j][0];
    //             int wt = adj[i][j][1];

    //             adjList[u].push_back({v, wt});
    //             adjList[v].push_back({u, wt});
    //         }
    //     }

    //     // distance : node
    //     priority_queue<pair<int, int>> minHeap;
    //     vector<int> dist(V, -1);

    //     dist[S] = 0;
    //     minHeap.push({0, S});
    //     while(!minHeap.empty()) {
    //         int distance = minHeap.top().first;
    //         int node = minHeap.top().second;
    //         minHeap.pop();

    //         for(auto neighbour : adjList[node]) {
    //             int v = neighbour.first;
    //             int wt = neighbour.second;

    //             int newDist = distance + wt;

    //             if(dist[v] == -1 or dist[v] > newDist) {
    //                 dist[v] = newDist;
    //                 minHeap.push({newDist, v});
    //             }
    //         }
    //     }

    //     return dist;
    // }

    // Using Set
    // TC -> E*(logV)
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<vector<pair<int, int>>> adjList(V);
        for (int i = 0; i < V; i++)
        {
            int u = i;
            for (int j = 0; j < adj[i].size(); j++)
            {
                int v = adj[i][j][0];
                int wt = adj[i][j][1];

                adjList[u].push_back({v, wt});
                adjList[v].push_back({u, wt});
            }
        }

        // distance, node
        set<pair<int, int>> st;
        vector<int> dist(V, -1);

        dist[S] = 0;
        st.insert({0, S});
        while (!st.empty())
        {
            pair<int, int> p = *st.begin();
            int distance = p.first;
            int node = p.second;
            st.erase(st.begin());

            for (auto neighbour : adjList[node])
            {
                int v = neighbour.first;
                int wt = neighbour.second;

                int newDist = distance + wt;

                if (dist[v] == -1 or dist[v] > newDist)
                {
                    if (dist[v] != -1)
                    {
                        st.erase({dist[v], v});
                    }

                    dist[v] = newDist;
                    st.insert({newDist, v});
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
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends