//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int equalSum(int N, vector<int> &A) {
        int left = 0, right = N-1;
        long long int leftSum = A[left], rightSum = A[right];
        
        while(left <= right) {
            if(leftSum == rightSum) {
                if(left == right){
                    return (left + 1);
                }
                
                left++;
                right--;
                leftSum += A[left];
                rightSum += A[right];
            } else if(leftSum < rightSum) {
                left++;
                leftSum += A[left];
            } else {
                right--;
                rightSum += A[right];
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N; 
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        int res = obj.equalSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends