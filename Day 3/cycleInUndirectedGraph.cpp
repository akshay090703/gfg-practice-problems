#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Solution
{
public:
    bool bfs(vector<int> adj[], unordered_map<int, bool> &isVisited, unordered_map<int, int> &parent, int node)
    {
        queue<int> q;
        q.push(node);
        isVisited[node] = true;
        parent[node] = -1;

        while (!q.empty())
        {
            int currNode = q.front();
            q.pop();

            for (auto neighbour : adj[currNode])
            {
                if (!isVisited[neighbour])
                {
                    q.push(neighbour);
                    isVisited[neighbour] = true;
                    parent[neighbour] = currNode;
                }
                else if (isVisited[neighbour] && parent[currNode] != neighbour)
                {
                    return true;
                }
            }
        }

        return false;
    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {

        unordered_map<int, bool> isVisited;
        unordered_map<int, int> parent;

        for (int i = 0; i < V; i++)
        {
            if (!isVisited[i])
            {
                bool ans = bfs(adj, isVisited, parent, i);
                if (ans)
                    return true;
            }
        }

        return false;
    }
};

int main()
{

    return 0;
}