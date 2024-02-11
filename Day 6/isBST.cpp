#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    bool isBST(Node *root, int min, int max)
    {
        if (!root)
            return true;

        if (min >= root->data || root->data >= max)
            return false;
        else
        {
            bool leftAns = isBST(root->left, min, root->data);
            bool rightAns = isBST(root->right, root->data, max);
            return leftAns && rightAns;
        }
    }

    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node *root)
    {
        return isBST(root, INT_MIN, INT_MAX);
    }
};

int main()
{

    return 0;
}