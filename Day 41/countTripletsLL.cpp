//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void push(struct Node** head_ref, int new_data)
{
   
    struct Node* new_node = new Node(new_data);
    
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
} 

int countTriplets(struct Node* head, int x) ;

/* Driver program to test count function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n , x ,i , num;
        struct Node *head = NULL;
        cin>>n>>x;
        for(i=0;i<n;i++)
        {
            cin>>num;
            push(&head,num);
        }
 
    /* Check the count function */
    cout <<countTriplets(head, x)<< endl;
    }
    return 0;
}
// } Driver Code Ends


//User function Template for C++

int countTriplets(struct Node* head, int x) 
{
    // storing the linked list into an array
    vector<int> arr;
    Node *temp = head;
    while(temp) {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    
    int n = arr.size();
    int count = 0;
    if(n < 3) {
        return count;
    }
    
    for(int i = 0; i < n-2; i++) {
        int start = i+1;
        int end = n-1;
        while(start < end) {
            int sum = arr[i] + arr[start] + arr[end];
            
            if(sum == x) {
                count++;
                // cout<< arr[i] << " "<< arr[start] << " " << arr[end]<< endl;
                start++;
                end--;
            } else if(sum > x) {
                end--;
            } else {
                start++;
            }
        }
    }

    return count;
} 