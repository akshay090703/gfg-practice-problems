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
// structure of the node is as follows

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};

*/
class Solution
{
public:
    struct Node *makeUnion(struct Node *head1, struct Node *head2)
    {
        set<int> minSet;

        while (head1)
        {
            minSet.insert(head1->data);
            head1 = head1->next;
        }

        while (head2)
        {
            minSet.insert(head2->data);
            head2 = head2->next;
        }

        struct Node *new_head = nullptr;
        struct Node *temp = nullptr;
        for (auto it = minSet.begin(); it != minSet.end(); it++)
        {
            Node *newNode = new Node(*it);

            if (!new_head)
            {
                new_head = newNode;
                temp = newNode;
            }
            else
            {
                temp->next = newNode;
                temp = temp->next;
            }
        }

        return new_head;
    }
};

//{ Driver Code Starts.

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);
        Solution obj;
        Node *head = obj.makeUnion(first, second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends