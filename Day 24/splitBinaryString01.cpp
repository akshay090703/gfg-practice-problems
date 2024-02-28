//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int maxSubStr(string str)
    {
        int count = 0;
        int numOfZeros = 0, numOfOnes = 0;

        for (char c : str)
        {
            if (c == '0')
            {
                numOfZeros++;
            }
            else
            {
                numOfOnes++;
            }

            if (numOfZeros == numOfOnes)
            {
                count++;
            }
        }

        if (numOfZeros != numOfOnes)
        {
            return -1;
        }

        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.maxSubStr(str);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends