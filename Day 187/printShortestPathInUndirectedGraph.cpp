//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adjList(n + 1);
        for (int i = 0; i < m; i++)
        { // Corrected loop condition
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }

        // Min-heap: distance, node
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, 1});

        vector<int> dist(n + 1, INT_MAX);
        dist[1] = 0;

        vector<int> parent(n + 1, -1);
        parent[1] = -1;
        while (!minHeap.empty())
        {
            int distance = minHeap.top().first;
            int node = minHeap.top().second;
            minHeap.pop();

            for (auto neighbour : adjList[node])
            {
                int v = neighbour.first;
                int wt = neighbour.second;

                int newDist = distance + wt;
                if (dist[v] > newDist)
                {
                    dist[v] = newDist;
                    parent[v] = node;

                    minHeap.push({newDist, v});
                }
            }
        }

        if (dist[n] == INT_MAX)
            return {-1};

        vector<int> path;
        int node = n;
        while (node != -1)
        {
            path.push_back(node);
            node = parent[node];
        }

        path.push_back(dist[n]);
        reverse(path.begin(), path.end());

        return path;
    }
};

//{ Driver Code Starts.
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++)
        {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0])
        {
        }
        else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends