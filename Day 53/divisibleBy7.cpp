//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int isdivisible7(string num)
    {
        int n = num.length();
        int rem = 0;

        for (int i = 0; i < n; i++)
        {
            rem = (rem * 10) + (num[i] - '0');

            rem %= 7;
        }

        return rem % 7 == 0 ? true : false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isdivisible7(s) << endl;
    }
    return 0;
}
// } Driver Code Ends