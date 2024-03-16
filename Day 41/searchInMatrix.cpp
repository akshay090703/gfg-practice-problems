//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    bool binarySearch(vector<int> &row, int X) {
        int start = 0;
        int end = row.size();
        while(start <= end) {
            int mid = start + ((end - start) / 2);
            if(row[mid] == X) {
                return true;
            } else if(row[mid] > X) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        return false;
    }

	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    for(int i = 0; i<N; i++) {
	        if(mat[i][M-1] >= X) {
	            if(binarySearch(mat[i], X)) {
	                return 1;
	            }
	        } 
	    }
	    
	    return false;
	}
};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}
// } Driver Code Ends