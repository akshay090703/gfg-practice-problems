//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest(int arr[], int n, int target) 
    { 
        int start = 0;
        int end = n-1;
        int mid;
      
        while(start <= end) {
            mid = start + ((end - start)/2);
            if(arr[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        int diff = abs(target - arr[mid]);
        if(mid > 0 and abs(arr[mid-1] - target) < diff) {
            return arr[mid-1];
        } else if(mid < n-1 and abs(arr[mid+1] - target) <= diff) {
            return arr[mid+1];
        }
        
        return arr[mid];
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,target;
        cin>>n>>target;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(arr,n,target)<<endl;
    }
}

// } Driver Code Ends
