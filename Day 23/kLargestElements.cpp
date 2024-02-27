//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    vector<int> kLargest(int arr[], int n, int k)
    {
        // min heap
        // we will make sure that it is always of size k
        // priority queue takes log n for insertion and deletion
        priority_queue<int, vector<int>, greater<int>> pqmin;

        for (int i = 0; i < k; i++)
        {
            pqmin.push(arr[i]);
        }

        for (int i = k; i < n; i++)
        {
            if (pqmin.size() == k and pqmin.top() < arr[i])
            {
                pqmin.pop(); // removes the smallest element in heap
                pqmin.push(arr[i]);
            }
        }

        vector<int> ans(k);
        for (int i = 1; i <= k; i++)
        {
            ans[k - i] = pqmin.top();
            pqmin.pop();
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
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends