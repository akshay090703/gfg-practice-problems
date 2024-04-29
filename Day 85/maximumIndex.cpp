//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n)
    {
        vector<int> minArr(n), maxArr(n);

        minArr[0] = a[0];
        for (int i = 1; i < n; i++)
        {
            minArr[i] = min(minArr[i - 1], a[i]);
        }

        maxArr[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            maxArr[i] = max(maxArr[i + 1], a[i]);
        }

        int max_idx = -1;
        int left = 0, right = 0;
        while (left < n and right < n)
        {
            if (minArr[left] <= maxArr[right])
            {
                max_idx = max(max_idx, right - left);
                right++;
            }
            else
            {
                left++;
            }
        }

        return max_idx;
    }
};

//{ Driver Code Starts.

/* Driver program to test above functions */
int main()
{
    int T;
    // testcases
    cin >> T;
    while (T--)
    {
        int num;
        // size of array
        cin >> num;
        int arr[num];

        // inserting elements
        for (int i = 0; i < num; i++)
            cin >> arr[i];
        Solution ob;

        // calling maxIndexDiff() function
        cout << ob.maxIndexDiff(arr, num) << endl;
    }
    return 0;
}
// } Driver Code Ends