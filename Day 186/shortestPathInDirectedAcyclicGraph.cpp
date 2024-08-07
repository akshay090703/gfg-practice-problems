//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    void dfs(vector<vector<pair<int, int>>> &adjList, vector<bool> &isVisited, stack<int> &st, int node)
    {
        isVisited[node] = true;

        for (auto neighbour : adjList[node])
        {
            int v = neighbour.first;
            int wt = neighbour.second;

            if (!isVisited[v])
            {
                dfs(adjList, isVisited, st, v);
            }
        }

        st.push(node);
    }

    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adjList(N);
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adjList[u].push_back({v, wt});
        }

        vector<bool> isVisited(N, false);
        stack<int> st;
        for (int i = 0; i < N; i++)
        {
            if (!isVisited[i])
            {
                dfs(adjList, isVisited, st, i);
            }
        }

        vector<int> dist(N, INT_MAX);
        dist[0] = 0;

        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            if (dist[node] != INT_MAX)
            {
                for (auto neighbour : adjList[node])
                {
                    int v = neighbour.first;
                    int wt = neighbour.second;

                    if (dist[node] + wt < dist[v])
                    {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
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
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends