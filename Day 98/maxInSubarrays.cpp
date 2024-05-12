//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findingMax(queue<int> q)
    {
        int maxi = INT_MIN;

        while (!q.empty())
        {
            maxi = max(maxi, q.front());

            q.pop();
        }

        return maxi;
    }

    vector<int> max_of_subarrays(vector<int> arr, int n, int k)
    {
        vector<int> result;

        queue<int> q;
        int maxi = INT_MIN;

        for (int i = 0; i < k; i++)
        {
            q.push(arr[i]);
            maxi = max(maxi, arr[i]);
        }

        result.push_back(maxi);

        for (int i = k; i < n; i++)
        {
            int temp = q.front();

            q.pop();

            if (maxi == temp)
            {
                maxi = findingMax(q);
            }

            maxi = max(maxi, arr[i]);
            q.push(arr[i]);

            result.push_back(maxi);
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

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends