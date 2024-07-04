//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node *flatten(Node *root);

int main(void)
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, flag = 1, flag1 = 1;
        struct Node *temp = NULL;
        struct Node *head = NULL;
        struct Node *pre = NULL;
        struct Node *tempB = NULL;
        struct Node *preB = NULL;
        cin >> n;
        int work[n];
        for (int i = 0; i < n; i++)
            cin >> work[i];
        for (int i = 0; i < n; i++)
        {
            m = work[i];
            --m;
            int data;
            scanf("%d", &data);
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;

            if (flag)
            {
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            }
            else
            {
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            for (int j = 0; j < m; j++)
            {

                int temp_data;
                scanf("%d", &temp_data);
                tempB = new Node(temp_data);

                if (flag1)
                {
                    temp->bottom = tempB;
                    preB = tempB;
                    flag1 = 0;
                }
                else
                {
                    preB->bottom = tempB;
                    preB = tempB;
                }
            }
        }
        Node *fun = head;
        Node *fun2 = head;

        Node *root = flatten(head);
        printList(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

/*  Function which returns the  root of
    the flattened linked list. */
Node *mergeLists(Node *root1, Node *root2)
{
    if (!root1)
        return root2;
    if (!root2)
        return root1;

    Node *new_head = nullptr;
    if (root1->data <= root2->data)
    {
        new_head = root1;
        root1 = root1->bottom;
    }
    else
    {
        new_head = root2;
        root2 = root2->bottom;
    }

    Node *temp = new_head;
    while (root1 and root2)
    {
        if (root1->data <= root2->data)
        {
            temp->bottom = root1;
            root1 = root1->bottom;
        }
        else
        {
            temp->bottom = root2;
            root2 = root2->bottom;
        }

        temp = temp->bottom;
    }

    if (root1)
        temp->bottom = root1;
    if (root2)
        temp->bottom = root2;

    return new_head;
}

Node *flatten(Node *root)
{
    if (!root or !root->next)
        return root;

    Node *temp = root->next;
    while (temp)
    {
        root = mergeLists(root, temp);
        temp = temp->next;
    }

    root->next = nullptr;

    return root;
}
