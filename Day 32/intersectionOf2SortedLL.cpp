//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *inputList(int size)
{
    Node *head, *tail;
    int val;

    cin >> val;
    head = tail = new Node(val);

    while (--size)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    if (n)
        while (n)
        {
            cout << n->data << " ";
            n = n->next;
        }
    else
        cout << " ";
}

// } Driver Code Ends
/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution
{
public:
    Node *findIntersection(Node *head1, Node *head2)
    {
        Node *head = nullptr;
        Node *tail = nullptr;

        while (head1 && head2)
        {
            if (head1->data > head2->data)
            {
                head2 = head2->next;
            }
            else if (head1->data < head2->data)
            {
                head1 = head1->next;
            }
            else
            {
                Node *new_node = new Node(head1->data);

                if (!head)
                {
                    head = new_node;
                    tail = head;
                }
                else
                {
                    tail->next = new_node;
                    tail = new_node;
                }

                head1 = head1->next;
                head2 = head2->next;
            }
        }

        return head;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        Node *head1 = inputList(n);
        Node *head2 = inputList(m);

        Solution ob;
        Node *result = ob.findIntersection(head1, head2);

        printList(result);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends