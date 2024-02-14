#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    void bfs(vector<int> adjList[], unordered_map<int, bool> &isVisited, vector<int> &ans, int node)
    {
        queue<int> q;
        q.push(node);
        isVisited[node] = true;

        while (!q.empty())
        {
            int currNode = q.front();
            q.pop();

            ans.push_back(currNode);

            for (auto neighbour : adjList[currNode])
            {
                if (!isVisited[neighbour])
                {
                    q.push(neighbour);
                    isVisited[neighbour] = true;
                }
            }
        }
    }

    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        unordered_map<int, bool> isVisited;
        vector<int> ans;

        bfs(adj, isVisited, ans, 0);

        return ans;
    }
};

int main()
{

    return 0;
}