//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> ans;
        int i = 1, j = k;
        
        // max heap
        // value : index
        priority_queue<pair<int,int>> pq; 
        for(int a = 0; a<k; a++) {
            pq.push({arr[a], a});
        }
        
        ans.push_back(pq.top().first);
        
        while(j<n) {
            pq.push({arr[j], j});
            
            // pop all elements that do not fit in the window
            while(pq.top().second < i) {
                pq.pop();
            }
            ans.push_back(pq.top().first);
            
            i++;
            j++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
