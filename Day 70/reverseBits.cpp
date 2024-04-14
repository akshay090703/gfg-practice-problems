//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long reversedBits(long long x)
    {
        string bitsForm = bitset<32>(x).to_string();

        reverse(bitsForm.begin(), bitsForm.end());

        long long resultedForm = bitset<32>(bitsForm).to_ullong();

        return resultedForm;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long X;

        cin >> X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends