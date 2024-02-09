#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        this->data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    bool sumChecker(Node *root, int leftSum, int rightSum)
    {
        return (root->data == leftSum + rightSum);
    }

    int solve(Node *root)
    {
        if (!root)
        {
            return 0;
        }

        if (!root->left && !root->right)
        {
            return root->data;
        }

        int leftSum = solve(root->left);
        int rightSum = solve(root->right);

        if (leftSum == -1 || rightSum == -1)
        {
            return -1;
        }

        int totalSum = leftSum + rightSum;

        if (sumChecker(root, leftSum, rightSum))
        {
            return totalSum;
        }

        return -1;
    }

    int isSumProperty(Node *root)
    {
        int sumVal = solve(root);

        if (sumVal == -1)
        {
            return 0;
        }

        return 1;
    }
};

int main()
{

    return 0;
}