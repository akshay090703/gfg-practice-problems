//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
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
        Node *next = nullptr;
        Node *curr = head;

        while (curr)
        {
            next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    Node *compute(Node *head)
    {
        head = reverseLL(head);

        Node *temp = head;
        Node *prev = nullptr;
        int comparingVal = INT_MIN;
        while (temp)
        {
            if (comparingVal <= temp->data)
            {
                comparingVal = temp->data;
                prev = temp;
                temp = temp->next;
            }
            else
            {
                Node *toBeDeleted = temp;
                temp = temp->next;

                prev->next = temp;
                delete toBeDeleted;
            }
        }

        return reverseLL(head);
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for (int i = 0; i < K; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout << endl;
    }
}

// } Driver Code Ends