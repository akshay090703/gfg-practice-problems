//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        long long int start = 1;
        long long int end = x;
        while(start <= end) {
            long long int mid = start + ((end-start)/2);
            if(mid * mid > x) {
                end = mid-1;
            } else if(mid*mid < x) {
                if((mid+1) * (mid+1) > x) {
                    return mid;
                }
                start = mid + 1;
            } else {
                return mid;
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends
