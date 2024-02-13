#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

vector<int> leftView(Node *root)
{
    if (!root)
    {
        return {};
    }

    // First value for the level and second for the first value
    map<int, int> m;

    // First value for level and second for current Node
    queue<pair<int, Node *>> q;

    q.push({0, root});

    while (!q.empty())
    {
        pair<int, Node *> currPair = q.front();
        q.pop();

        int level = currPair.first;
        Node *currNode = currPair.second;

        if (m.find(level) == m.end())
        {
            m[level] = currNode->data;
        }

        if (currNode->left)
        {
            q.push({level + 1, currNode->left});
        }

        if (currNode->right)
        {
            q.push({level + 1, currNode->right});
        }
    }

    vector<int> ans;
    for (auto node : m)
    {
        ans.push_back(node.second);
    }

    return ans;
}

int main()
{

    return 0;
}