//{ Driver Code Starts
// Initial template for C++

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

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends
// User function template for C++

/*

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
    Node *addOne(Node *head)
    {
        Node *curr = head;
        Node *prev = nullptr;
        Node *next = nullptr;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        Node *rev_head = prev;

        if (rev_head->data + 1 != 10)
        {
            rev_head->data += 1;
        }
        else
        {
            rev_head->data = 0;
            rev_head = rev_head->next;
            while (rev_head and rev_head->data + 1 == 10)
            {
                rev_head->data = 0;
                rev_head = rev_head->next;
            }

            if (rev_head)
            {
                rev_head->data += 1;
            }
            else
            {
                Node *new_node = new Node(1);
                head->next = new_node;
            }
        }

        curr = prev;
        prev = nullptr;
        next = nullptr;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Node *head = new Node(s[0] - '0');
        Node *tail = head;
        for (int i = 1; i < s.size(); i++)
        {
            tail->next = new Node(s[i] - '0');
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends