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
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

// } Driver Code Ends
/* structure of list node:

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
        unordered_map<int, bool> occurance;
        Node *temp = head2;
        while (temp)
        {
            occurance[temp->data] = true;
            temp = temp->next;
        }

        temp = head1;
        Node *new_temp = nullptr;
        Node *new_head = nullptr;
        while (temp)
        {
            if (occurance[temp->data])
            {
                if (!new_head)
                {
                    new_head = new Node(temp->data);
                    new_temp = new_head;
                }
                else
                {
                    Node *newNode = new Node(temp->data);
                    new_temp->next = newNode;
                    new_temp = newNode;
                }
            }

            temp = temp->next;
        }

        return new_head;
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

        cin >> n;
        Node *head1 = inputList(n);

        cin >> m;
        Node *head2 = inputList(m);
        Solution obj;
        Node *result = obj.findIntersection(head1, head2);

        printList(result);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends