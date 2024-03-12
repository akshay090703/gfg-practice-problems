//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> makeBeautiful(vector<int> arr)
    {
        vector<int> result;
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            int m = result.size();
            if (m == 0)
            {
                result.push_back(arr[i]);
            }
            else
            {
                if ((result[m - 1] >= 0 and arr[i] < 0) or (result[m - 1] < 0 and arr[i] >= 0))
                {
                    result.pop_back();
                }
                else
                {
                    result.push_back(arr[i]);
                }
            }
        }

        return result;
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
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends