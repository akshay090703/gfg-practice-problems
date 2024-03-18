//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minRepeats(string A, string B)
    {
        int n = A.length();
        int m = B.length();

        // 10 just to be on the safe side
        int repeated = (m / n) + 10;

        string concatinated_A = "";
        int i = 0;
        while (i < repeated and concatinated_A.find(B) == string::npos)
        {
            concatinated_A += A;

            i++;
        }

        if (concatinated_A.find(B) != string::npos)
        {
            return i;
        }

        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends