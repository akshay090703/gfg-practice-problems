//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head)
{
    if (head == NULL)
        return;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data)
{
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL)
    {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution
{
public:
    bool isVowel(Node *head)
    {
        if (head == nullptr)
            return false;

        char data = head->data;

        if (data == 'a' or data == 'e' or data == 'i' or data == 'o' or data == 'u')
            return true;

        return false;
    }

    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node *arrangeCV(Node *head)
    {
        Node *vowelHead = nullptr, *vowelTail = nullptr;
        Node *consoHead = nullptr, *consoTail = nullptr;

        Node *temp = head;

        while (temp)
        {
            if (isVowel(temp))
            {
                if (!vowelHead)
                {
                    vowelHead = temp;
                    vowelTail = temp;
                }
                else
                {
                    vowelTail->next = temp;
                    vowelTail = temp;
                }
            }
            else
            {
                if (!consoHead)
                {
                    consoHead = temp;
                    consoTail = temp;
                }
                else
                {
                    consoTail->next = temp;
                    consoTail = temp;
                }
            }

            temp = temp->next;
        }

        if (vowelTail)
            vowelTail->next = nullptr;
        if (consoTail)
            consoTail->next = nullptr;

        if (vowelHead)
        {
            vowelTail->next = consoHead;
            return vowelHead;
        }

        return consoHead;
    }
};

//{ Driver Code Starts.

// task is to complete this function
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--)
        {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}

// } Driver Code Ends