#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node
{
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
        {
            return nullptr;
        }

        unordered_map<int, Node *> cloneMap;
        queue<Node *> q;

        Node *new_head = new Node(node->val);
        cloneMap[node->val] = new_head;
        q.push(node);

        while (!q.empty())
        {
            Node *currNode = q.front();
            q.pop();

            for (Node *neighbor : currNode->neighbors)
            {
                if (cloneMap.find(neighbor->val) == cloneMap.end())
                {
                    Node *new_neighbor = new Node(neighbor->val);
                    cloneMap[neighbor->val] = new_neighbor;
                    q.push(neighbor);
                }

                cloneMap[currNode->val]->neighbors.push_back(cloneMap[neighbor->val]);
            }
        }

        return new_head;
    }
};

int main()
{

    return 0;
}