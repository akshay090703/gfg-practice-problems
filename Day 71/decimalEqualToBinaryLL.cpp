//{ Driver Code Starts
// Program to check if linked list is empty or not
#include <iostream>
using namespace std;
const long long unsigned int MOD = 1000000007;

/* Link list Node */
struct Node
{
    bool data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// } Driver Code Ends
/* Below global variable is declared in code for modulo arithmetic
const long long unsigned int MOD = 1000000007; */

/* Link list Node/
struct Node
{
    bool data;   // NOTE data is bool
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */

class Solution
{
public:
    long long unsigned int pow(int a, int b)
    {
        if (b == 0)
            return 1;
        long long unsigned int ans = 1;

        while (b--)
        {
            ans = (ans * 2) % MOD;
        }

        return ans;
    }

    // Should return decimal equivalent modulo 1000000007 of binary linked list
    long long unsigned int decimalValue(Node *head)
    {
        if (!head)
            return 0;

        Node *temp = head;
        int length = 0;
        while (temp)
        {
            length++;
            temp = temp->next;
        }

        int multiplier = length - 1;
        long long unsigned int ans = 0;
        long long unsigned int powersOfTwo[length];
        powersOfTwo[0] = 1;

        for (int i = 1; i < length; i++)
        {
            powersOfTwo[i] = (powersOfTwo[i - 1] * 2) % MOD;
        }

        temp = head;
        while (temp)
        {
            ans = (ans + powersOfTwo[multiplier] * temp->data) % MOD;
            multiplier--;
            temp = temp->next;
        }

        return ans;
    }
};

//{ Driver Code Starts.

void append(struct Node **head_ref, struct Node **tail_ref, bool new_data)
{

    struct Node *new_node = new Node(new_data);

    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

bool isEmpty(struct Node *head);

/* Driver program to test above function*/
int main()
{
    bool l;
    int i, n, T;

    cin >> T;

    while (T--)
    {
        struct Node *head = NULL, *tail = NULL;

        cin >> n;
        for (i = 1; i <= n; i++)
        {
            cin >> l;
            append(&head, &tail, l);
        }
        Solution obj;
        cout << obj.decimalValue(head) << endl;
    }
    return 0;
}
// } Driver Code Ends