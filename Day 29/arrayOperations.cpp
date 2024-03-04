//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int arrayOperations(int n, vector<int> &arr)
    {
        int numOfZeroes = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                numOfZeroes++;
            }
        }

        if (numOfZeroes == 0)
        {
            return -1;
        }

        int operations = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 0)
            {
                while (i < n and arr[i] != 0)
                {
                    i++;
                }
                operations++;
            }
        }

        return operations;
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

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution obj;
        int res = obj.arrayOperations(n, arr);

        cout << res << endl;
    }
}

// } Driver Code Ends