//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int minOperations(int arr[], int n, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < n; i++)
        {
            minHeap.push(arr[i]);
        }

        int count = 0;

        while (minHeap.size() >= 2 and minHeap.top() < k)
        {
            int top = minHeap.top();
            minHeap.pop();

            int secondTop = minHeap.top();
            minHeap.pop();

            int sum = top + secondTop;
            minHeap.push(sum);

            count++;
        }

        if (minHeap.size() < 2 and minHeap.top() < k)
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
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        int ans = obj.minOperations(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends