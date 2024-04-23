//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int segregate(int arr[], int n)
    {
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= 0)
            {
                swap(arr[i], arr[j]);
                j++;
            }
        }

        return j;
    }

    int solve(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (abs(arr[i]) - 1 < n and arr[abs(arr[i]) - 1] > 0)
            {
                arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                return i + 1;
            }
        }

        return n + 1;
    }

    // Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n)
    {
        int segregation = segregate(arr, n);
        return solve(arr + segregation, n - segregation);
    }
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main()
{

    // taking testcases
    int t;
    cin >> t;
    while (t--)
    {

        // input number n
        int n;
        cin >> n;
        int arr[n];

        // adding elements to the array
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        // calling missingNumber()
        cout << ob.missingNumber(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends