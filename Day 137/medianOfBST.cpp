//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
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

float findMedian(struct Node *node);

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main()
{

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    // cout << t << endl;
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);

        // getline(cin, s);

        cout << findMedian(root) << endl;

        // cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends

/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

void findNodes(struct Node *root, int &totalNodes)
{
    if (!root)
        return;

    totalNodes++;

    findNodes(root->left, totalNodes);
    findNodes(root->right, totalNodes);
}

void findMedian(struct Node *root, float &median, bool &isOdd, int totalNodes, int &currNode)
{
    if (!root)
    {
        return;
    }

    findMedian(root->left, median, isOdd, totalNodes, currNode);

    currNode++;

    if (isOdd)
    {
        if (currNode == ((totalNodes + 1) / 2))
        {
            median = root->data;
        }
    }
    else
    {
        if (currNode == (totalNodes / 2) or currNode == ((totalNodes / 2) + 1))
        {
            median += root->data;
        }
    }

    findMedian(root->right, median, isOdd, totalNodes, currNode);
}

// your task is to complete the Function
// Function should return median of the BST
float findMedian(struct Node *root)
{
    int totalNodes = 0;
    findNodes(root, totalNodes);

    bool isOdd = true;
    if (totalNodes % 2 == 0)
        isOdd = false;

    float median = 0;
    int currNode = 0;
    findMedian(root, median, isOdd, totalNodes, currNode);

    if (!isOdd)
        median /= 2;

    return median;
}
