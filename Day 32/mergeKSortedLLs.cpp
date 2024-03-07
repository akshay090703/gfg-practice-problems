//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
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

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

// } Driver Code Ends
/*Linked list Node structure

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
    Node *mergeSortedLLs(Node *head1, Node *head2)
    {
        Node *new_head = nullptr;
        Node *tail = nullptr;

        while (head1 and head2)
        {
            if (head1->data <= head2->data)
            {
                if (!new_head)
                {
                    new_head = head1;
                    tail = head1;
                }
                else
                {
                    tail->next = head1;
                    tail = tail->next;
                }

                head1 = head1->next;
            }
            else
            {
                if (!new_head)
                {
                    new_head = head2;
                    tail = head2;
                }
                else
                {
                    tail->next = head2;
                    tail = tail->next;
                }

                head2 = head2->next;
            }
        }

        if (head1)
        {
            if (!new_head)
            {
                new_head = head1;
            }
            else
            {
                tail->next = head1;
            }
        }

        if (head2)
        {
            if (!new_head)
            {
                new_head = head2;
            }
            else
            {
                tail->next = head2;
            }
        }

        return new_head;
    }

    // Function to merge K sorted linked list.
    Node *mergeKLists(Node *arr[], int K)
    {
        vector<Node *> result;
        for (int i = 0; i < K; i++)
        {
            result.push_back(arr[i]);
        }

        while (result.size() > 1)
        {
            Node *head = mergeSortedLLs(result[0], result[1]);
            result.erase(result.begin());
            result.erase(result.begin());
            result.push_back(head);
        }

        return result[0];
    }
};

//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        struct Node *arr[N];
        for (int j = 0; j < N; j++)
        {
            int n;
            cin >> n;

            int x;
            cin >> x;
            arr[j] = new Node(x);
            Node *curr = arr[j];
            n--;

            for (int i = 0; i < n; i++)
            {
                cin >> x;
                Node *temp = new Node(x);
                curr->next = temp;
                curr = temp;
            }
        }
        Solution obj;
        Node *res = obj.mergeKLists(arr, N);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends