//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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
/* Structure of the linked list node is as
struct Node
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

class Solution
{
public:
    // Function to sort the given linked list using Merge Sort.
    Node *findingMid(Node *head)
    {
        Node *slow = head;
        Node *fast = head;

        while (fast->next and fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    Node *merge(Node *left, Node *right)
    {
        Node *head = nullptr;
        Node *tail = nullptr;

        while (left and right)
        {
            if (left->data <= right->data)
            {
                if (!head)
                {
                    head = left;
                    tail = head;
                }
                else
                {
                    tail->next = left;
                    tail = tail->next;
                }

                left = left->next;
            }
            else
            {
                if (!head)
                {
                    head = right;
                    tail = head;
                }
                else
                {
                    tail->next = right;
                    tail = tail->next;
                }

                right = right->next;
            }
        }

        if (left)
        {
            if (!head)
            {
                head = left;
            }
            else
            {
                tail->next = left;
            }
        }

        if (right)
        {
            if (!head)
            {
                head = right;
            }
            else
            {
                tail->next = right;
            }
        }

        return head;
    }

    void solve(Node *&head)
    {
        if (!head or !head->next)
            return;

        Node *mid = findingMid(head);
        Node *left = head;
        Node *right = mid->next;
        mid->next = nullptr;

        solve(left);
        solve(right);

        head = merge(left, right);
    }

    Node *mergeSort(Node *head)
    {
        solve(head);

        return head;
    }
};

//{ Driver Code Starts.

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node **head_ref, int new_data)
{
    Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    long test;
    cin >> test;
    while (test--)
    {
        struct Node *a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends