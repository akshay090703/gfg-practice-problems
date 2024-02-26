//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    int binarySearch(int arr[], int start, int end, int target, bool isLast, int n) {
        while(start <= end) {
            int mid = start + ((end-start)/2);
            if(arr[mid] > target) {
                end = mid-1;
            } else if (arr[mid] < target) {
                start = mid+1;
            } else {
                if(isLast) {
                    if(mid == n-1 or arr[mid] != arr[mid+1]) {
                        return mid;
                    } else {
                        start = mid+1;
                    }
                } else {
                    if(mid == 0 or arr[mid] != arr[mid-1]) {
                        return mid;
                    } else {
                        end = mid-1;
                    }
                }
            }
        } 
        return -1;
    }
    
    vector<int> find(int arr[], int n , int x )
    {
        vector<int> ans;
        ans.push_back(binarySearch(arr, 0, n-1, x, false, n));
        ans.push_back(binarySearch(arr, 0, n-1, x, true, n));
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends
