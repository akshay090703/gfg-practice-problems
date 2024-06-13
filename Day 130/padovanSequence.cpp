//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int padovanSequence(int n)
    {
        if (n == 0 or n == 1 or n == 2)
            return 1;

        int prevPrevPrev = 1, prevPrev = 1, prev = 1, current = 1;

        for (int i = 3; i <= n; i++)
        {
            current = (prevPrev + prevPrevPrev) % 1000000007;
            prevPrevPrev = prevPrev;
            prevPrev = prev;
            prev = current;
        }

        return current;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}
// } Driver Code Ends