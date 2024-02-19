//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this function*/

class Solution
{
public:
    int maxLen(vector<int> &A, int n)
    {
        // first is for sum and second is for index
        unordered_map<int, int> cumulativeSum;
        int maxLength = 0;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += A[i];

            if (sum == 0)
            {
                maxLength = max(maxLength, i + 1);
            }

            if (cumulativeSum.find(sum) == cumulativeSum.end())
            {
                cumulativeSum[sum] = i;
            }
            else
            {
                maxLength = max(maxLength, i - cumulativeSum[sum]);
            }
        }

        return maxLength;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends