//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    bool isValidTimeToPaint(int arr[], int n, int k, long long maxTime)
    {
        int painters = 1;
        long long currTime = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > maxTime)
                return false;

            if (arr[i] + currTime > maxTime)
            {
                painters++;
                currTime = arr[i];

                if (painters > k)
                    return false;
            }
            else
            {
                currTime += arr[i];
            }
        }

        return true;
    }

    long long minTime(int arr[], int n, int k)
    {
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        long long start = 1, end = sum;
        long long res = -1;
        while (start <= end)
        {
            long long mid = start + ((end - start) / 2);

            if (isValidTimeToPaint(arr, n, k, mid))
            {
                end = mid - 1;
                res = mid;
            }
            else
            {
                start = mid + 1;
            }
        }

        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k, n;
        cin >> k >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minTime(arr, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends