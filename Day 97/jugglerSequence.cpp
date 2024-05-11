//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long oddSequence(long long n) {
        return pow(n, 1.5);
    }
    
    long long evenSequence(long long n) {
        return pow(n, 0.5);
    }
  
    vector<long long> jugglerSequence(long long n) {
        vector<long long> result;
        result.push_back(n);
        
        while(n > 1) {
            if(n % 2 == 0) {
                n = evenSequence(n);
                
                result.push_back(n);
            } else {
                n = oddSequence(n);
                
                result.push_back(n);
            }
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        Solution ob;
        vector<long long> ans = ob.jugglerSequence(n);
        for (long long u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends