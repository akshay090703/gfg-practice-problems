//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    
    Node *reverseLL(Node *node) {
        Node *prev = nullptr;
        Node *curr = node;
        Node *next = nullptr;
        
        while(curr) {
            next = curr->next;
            
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    struct Node * mergeResult(Node *node1, Node *node2)
    {
        if (!node1) return reverseLL(node2);
        if (!node2) return reverseLL(node1);
        
        Node *temp1 = node1;
        Node *prev1 = nullptr;
        Node *temp2 = node2;
        Node *prev2 = nullptr;
        Node *new_tail = node1->data <= node2->data ? node1 : node2;
        
        while(temp1 and temp2) {
            prev1 = temp1;
            prev2 = temp2;
            
            if(temp1 and temp2 and temp1->data <= temp2->data) {
                temp1 = temp1->next;
                while(temp1 and temp2 and temp1->data <= temp2->data) {
                    prev1 = temp1;
                    temp1 = temp1->next;
                }
                
                if(temp2) prev1->next = temp2;
            } else {
                temp2 = temp2->next;
                while(temp1 and temp2 and temp2->data < temp1->data) {
                    prev2 = temp2;
                    temp2 = temp2->next;
                }
                
                if(temp1) prev2->next = temp1;
            }
        }
        
        return reverseLL(new_tail);
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends