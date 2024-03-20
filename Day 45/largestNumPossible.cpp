//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    string findLargest(int N, int S)
    {
        if (S > 9 * N || (S == 0 && N > 1))
            return "-1";

        string ans = "";
        int temp = N;
        if (S == 0 && N == 1)
            return "0";

        if (S < 10)
        {
            while (temp--)
            {
                int digit = min(S, 9);
                ans += char('0' + digit);
                S -= digit;
            }
        }
        else
        {
            while (temp--)
            {
                if (S >= 9)
                {
                    ans += '9';
                    S -= 9;
                }
                else
                {
                    ans += char('0' + S);
                    S = 0;
                }
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, S;
        cin >> N >> S;

        Solution ob;
        cout << ob.findLargest(N, S) << "\n";
    }
    return 0;
}
// } Driver Code Ends