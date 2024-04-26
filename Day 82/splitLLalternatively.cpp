//{ Driver Code Starts

#include <iostream>
#include <stdio.h>
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

void append(struct Node **headRef, int newData)
{
    struct Node *new_node = new Node(newData);
    struct Node *last = *headRef;

    if (*headRef == NULL)
    {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

void alternatingSplitList(struct Node *);

struct Node *a;
struct Node *b;

int main()
{
    int test;
    cin >> test;

    while (test--)
    {
        a = b = NULL;
        struct Node *head = NULL;

        int n, k;
        cin >> n;

        while (n--)
        {
            cin >> k;
            append(&head, k);
        }

        alternatingSplitList(head);
        printList(a);
        printList(b);
    }
    return 0;
}

// } Driver Code Ends

/*
structure of node is as
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

/*
These are global variables to store heads of split lists
struct Node* a; //store head of first list
struct Node* b; //store head of second list

*/

void alternatingSplitList(struct Node *head)
{
    bool alternateLL = true;
    a = nullptr;
    b = nullptr;
    struct Node *temp1 = nullptr;
    struct Node *temp2 = nullptr;

    while (head)
    {
        struct Node *newNode = new Node(head->data);

        if (alternateLL)
        {
            if (!a)
            {
                a = newNode;
                temp1 = a;
            }
            else
            {
                temp1->next = newNode;
                temp1 = temp1->next;
            }
        }
        else
        {
            if (!b)
            {
                b = newNode;
                temp2 = b;
            }
            else
            {
                temp2->next = newNode;
                temp2 = temp2->next;
            }
        }

        alternateLL = !alternateLL;
        head = head->next;
    }
}
