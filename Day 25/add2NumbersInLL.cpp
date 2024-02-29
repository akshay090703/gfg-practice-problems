//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
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

// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    struct Node *reverseLL(struct Node *head)
    {
        struct Node *curr = head;
        struct Node *prev = nullptr;
        struct Node *next = nullptr;
        struct Node *new_head = nullptr;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;

            if (!next)
            {
                new_head = curr;
            }

            curr = next;
        }

        return new_head;
    }

    // Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        // Step 1: reverse the numbers LL
        struct Node *temp1 = reverseLL(first);
        struct Node *temp2 = reverseLL(second);

        // Step 2: Add and make a new LL
        int carry = 0;
        struct Node *head = nullptr;
        struct Node *tail = nullptr;

        while (temp1 or temp2 or carry != 0)
        {
            int val1 = 0;
            if (temp1)
                val1 = temp1->data;

            int val2 = 0;
            if (temp2)
            {
                val2 = temp2->data;
            }

            int sum = val1 + val2 + carry;
            struct Node *new_node = nullptr;

            new_node = new Node(sum % 10);
            carry = sum / 10;

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

            if (temp1)
                temp1 = temp1->next;

            if (temp2)
                temp2 = temp2->next;
        }

        head = reverseLL(head);

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

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends