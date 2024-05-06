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
/* Function to print linked list */

void append(struct Node **headRef, struct Node **tailRef, int newData)
{
    struct Node *new_node = new Node(newData);
    struct Node *last = *headRef;
    if (*headRef == NULL)
    {
        *headRef = new_node;
        *tailRef = *headRef;
        return;
    }

    (*tailRef)->next = new_node;
    *tailRef = (*tailRef)->next;
}

// A utility function to print a linked list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// } Driver Code Ends

/*
struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        data =x;
        next = NULL;
    }
};
*/

class Solution
{
public:
    Node *reverseLL(Node *head)
    {
        Node *prev = nullptr;
        Node *curr = head;
        Node *next = nullptr;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;

            curr = next;
        }

        return prev;
    }

    // your task is to complete this function
    void sort(Node **head)
    {
        Node *new_head = nullptr;
        Node *new_tail = nullptr;

        Node *desc_head = nullptr;
        Node *desc_tail = nullptr;

        Node *temp = *head;
        int i = 0;

        while (temp)
        {
            Node *next = temp->next;

            if (i % 2 == 0)
            {
                if (!new_head)
                {
                    new_head = temp;
                    new_tail = temp;
                }
                else
                {
                    new_tail->next = temp;
                    new_tail = temp;
                }

                new_tail->next = nullptr;
            }
            else
            {
                if (!desc_head)
                {
                    desc_head = temp;
                    desc_tail = temp;
                }
                else
                {
                    desc_tail->next = temp;
                    desc_tail = temp;
                }

                desc_tail->next = nullptr;
            }

            i++;
            temp = next;
        }

        if (desc_head)
            desc_head = reverseLL(desc_head);

        if (!new_head)
        {
            *head = desc_tail;
            return;
        }

        if (desc_head)
            new_tail->next = desc_head;

        *head = new_head;
    }
};

//{ Driver Code Starts.
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        struct Node *head = NULL;
        struct Node *tail = NULL;
        int n, k;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            append(&head, &tail, k);
        }
        Solution ob;
        ob.sort(&head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends