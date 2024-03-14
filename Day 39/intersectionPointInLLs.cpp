//{ Driver Code Starts
#include <iostream>

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
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

int intersectPoint(struct Node *head1, struct Node *head2);

vector<int> take(int n)
{
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
        cin >> ans[i];
    return ans;
}

Node *inputList(int size, vector<int> v)
{
    if (size == 0)
        return NULL;

    int val = v[0];

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        val = v[i + 1];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

/* Driver program to test above function*/
int main()
{
    srand(time(0));
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        int p = rand() % 3;

        vector<int> v1 = take(n1);
        vector<int> v2 = take(n2);
        vector<int> v3 = take(n3);

        Node *head1 = NULL;
        Node *head2 = NULL;
        Node *common = NULL;

        if (p == 0)
        {
            common = inputList(n3, v3);
            head1 = inputList(n1, v1);
            head2 = inputList(n2, v2);
        }
        else if (p == 1)
        {

            head1 = inputList(n1, v1);
            common = inputList(n3, v3);
            head2 = inputList(n2, v2);
        }
        else
        {

            head1 = inputList(n1, v1);
            head2 = inputList(n2, v2);
            common = inputList(n3, v3);
        }

        Node *temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

// Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node *head1, Node *head2)
{
    int length1 = 0, length2 = 0;

    Node *temp = head1;
    while (temp)
    {
        temp = temp->next;
        length1++;
    }

    temp = head2;
    while (temp)
    {
        temp = temp->next;
        length2++;
    }

    bool firstGreater = length1 >= length2 ? true : false;
    int diff = abs(length1 - length2);
    int count = 0;

    if (firstGreater)
    {
        temp = head1;
    }
    else
    {
        temp = head2;
    }

    while (count < diff)
    {
        temp = temp->next;
        count++;
    }

    Node *temp2 = nullptr;

    if (firstGreater)
    {
        temp2 = head2;
    }
    else
    {
        temp2 = head1;
    }

    while (temp and temp2 and temp != temp2)
    {
        temp = temp->next;
        temp2 = temp2->next;
    }

    if (!temp or !temp2)
        return -1;

    return temp->data;
}
