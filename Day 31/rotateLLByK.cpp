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

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    // Function to rotate a linked list.
    Node *rotate(Node *head, int k)
    {
        int n = 0;
        Node *temp = head;
        while (temp)
        {
            n++;
            temp = temp->next;
        }

        k = k % n;

        if (k == 0)
        {
            return head;
        }

        int count = 0;
        temp = head;
        Node *new_tail = nullptr;
        Node *new_head = nullptr;
        while (temp)
        {
            count++;

            if (count == k)
            {
                new_tail = temp;
            }
            else if (count == k + 1)
            {
                new_head = temp;

                if (count == n)
                {
                    temp->next = head;
                    break;
                }
            }
            else if (count == n)
            {
                temp->next = head;
                break;
            }

            temp = temp->next;
        }

        new_tail->next = nullptr;

        return new_head;
    }
};

//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
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
        int n, val, k;
        cin >> n;

        cin >> val;
        Node *head = new Node(val);
        Node *tail = head;

        for (int i = 0; i < n - 1; i++)
        {
            cin >> val;
            tail->next = new Node(val);
            tail = tail->next;
        }

        cin >> k;

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends