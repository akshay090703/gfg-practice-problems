//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    long long countTriplets(long long arr[], int n, long long sum)
    {
        // To ensure that the order i<j<k is maintained
        sort(arr, arr + n);

        long long count = 0;
        for (int i = 0; i < n - 2; i++)
        {
            long long reqSum = sum - arr[i];
            int start = i + 1, end = n - 1;
            while (start < end)
            {
                if (arr[start] + arr[end] >= reqSum)
                {
                    end--;
                }
                else
                {
                    count += end - start;
                    start++;
                }
            }
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
        int n;
        long long sum;
        cin >> n >> sum;
        long long arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countTriplets(arr, n, sum);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends