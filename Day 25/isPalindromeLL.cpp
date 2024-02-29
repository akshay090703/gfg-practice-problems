//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        int length = 0;
        Node *temp = head;
        while (temp)
        {
            temp = temp->next;
            length++;
        }

        int mid = (length - 1) / 2;
        Node *prev = nullptr;
        Node *next = nullptr;
        Node *curr = nullptr;
        temp = head;
        int i = 0;

        while (i <= mid and temp)
        {
            if (i + 1 == mid)
            {
                prev = temp;
            }

            if (i == mid)
            {
                curr = temp;
            }

            temp = temp->next;
            i++;
        }

        // reversing the second half of the LL
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // now curr is pointing to the last node
        curr = prev;
        temp = head;
        i = 0;
        int j = length - 1;

        while (i <= j)
        {
            if (curr->data != temp->data)
            {
                return false;
            }

            temp = temp->next;
            curr = curr->next;
            i++;
            j--;
        }

        return true;
    }
};

//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
    int T, i, n, l, firstdata;
    cin >> T;
    while (T--)
    {

        struct Node *head = NULL, *tail = NULL;
        cin >> n;
        // taking first data of LL
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        Solution obj;
        cout << obj.isPalindrome(head) << endl;
    }
    return 0;
}

// } Driver Code Ends