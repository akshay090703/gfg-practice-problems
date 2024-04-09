//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        int n = S.length();
        vector<int> charIndex(26, -1);
        int maxLen = 0;
        int start = -1;
    
        for (int i = 0; i < n; i++) {
            if (charIndex[S[i] - 'a'] != -1 && charIndex[S[i] - 'a'] > start) {
                start = charIndex[S[i] - 'a'];
            }
            
            charIndex[S[i] - 'a'] = i;
            maxLen = max(maxLen, i - start);
        }
    
        return maxLen;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends