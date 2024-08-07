//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Using DFS
    // 	void dfs(vector<int> adj[], vector<bool> &isVisited,stack<int> &topoSeq, int node) {
    // 	    isVisited[node] = true;

    // 	    for(auto neighbour : adj[node]) {
    // 	        if(!isVisited[neighbour]) {
    // 	            dfs(adj, isVisited, topoSeq, neighbour);
    // 	        }
    // 	    }

    // 	    topoSeq.push(node);
    // 	}

    // 	//Function to return list containing vertices in Topological order.
    // 	vector<int> topoSort(int V, vector<int> adj[])
    // 	{
    // 	    vector<bool> isVisited(V, false);
    // 	    stack<int> topoSeq;

    // 	    for(int i = 0; i<V; i++) {
    // 	        if(!isVisited[i]) {
    // 	            dfs(adj, isVisited, topoSeq, i);
    // 	        }
    // 	    }

    // 	    vector<int> result;
    // 	    while(!topoSeq.empty()) {
    // 	        result.push_back(topoSeq.top());
    // 	        topoSeq.pop();
    // 	    }

    // 	    return result;
    // 	}

    // Using Kahn's algorithm (BFS)
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> inDegree(V, 0);
        for (int u = 0; u < V; u++)
        {
            for (int v = 0; v < adj[u].size(); v++)
            {
                inDegree[adj[u][v]]++;
            }
        }

        vector<int> topoSort;
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
                topoSort.push_back(i);
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
                    topoSort.push_back(neighbour);
                }
            }
        }

        return topoSort;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<int> adj[])
{

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}
// } Driver Code Ends