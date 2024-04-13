//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// } Driver Code Ends
/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/
class Solution
{
public:
    Node *pairWiseSwap(struct Node *head)
    {
        if (!head or !head->next)
            return head;

        Node *firstNode = head;
        Node *secondNode = head->next;

        Node *new_head = secondNode;

        while (firstNode and secondNode)
        {
            Node *nextPair = secondNode->next;

            firstNode->next = nextPair;
            secondNode->next = firstNode;

            if (nextPair and nextPair->next)
            {
                firstNode->next = nextPair->next;
            }
            else
            {
                firstNode->next = nextPair;
            }

            firstNode = nextPair;
            secondNode = firstNode ? firstNode->next : nullptr;
        }

        return new_head;
    }
};

//{ Driver Code Starts.

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        map<Node *, int> mp;
        mp[head] = head->data;
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
            mp[tail] = tail->data;
        }
        struct Node *failure = new Node(-1);
        Solution ob;
        head = ob.pairWiseSwap(head);
        int flag = 0;
        struct Node *temp = head;
        while (temp)
        {
            if (mp[temp] != temp->data)
            {
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if (flag)
            printList(failure);
        else
            printList(head);
    }
    return 0;
}

// } Driver Code Ends