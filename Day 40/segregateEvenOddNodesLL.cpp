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
        cout << node->data << " ";
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
    Node *divide(int N, Node *head)
    {
        Node *evenHead = nullptr;
        Node *oddHead = nullptr;
        Node *tempEven = nullptr;
        Node *tempOdd = nullptr;
        Node *temp = head;

        while (temp)
        {
            if (temp->data % 2 == 0)
            {
                if (!evenHead)
                {
                    evenHead = temp;
                    tempEven = temp;
                }
                else
                {
                    tempEven->next = temp;
                    tempEven = tempEven->next;
                }
            }
            else
            {
                if (!oddHead)
                {
                    oddHead = temp;
                    tempOdd = temp;
                }
                else
                {
                    tempOdd->next = temp;
                    tempOdd = tempOdd->next;
                }
            }

            temp = temp->next;
        }

        if (!evenHead)
            return oddHead;
        if (!oddHead)
            return evenHead;

        tempEven->next = oddHead;
        tempOdd->next = nullptr;

        return evenHead;
    }
};

//{ Driver Code Starts.

int main()
{
    // code
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans);
    }
    return 0;
}

// } Driver Code Ends