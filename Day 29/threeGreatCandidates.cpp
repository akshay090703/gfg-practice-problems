//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    long long maxProduct(int arr[], int n)
    {
        long long max1 = INT_MIN;
        long long max2 = INT_MIN;
        long long max3 = INT_MIN;
        long long min1 = INT_MAX;
        long long min2 = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            long long element = arr[i];

            if (element > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = element;
            }
            else if (element > max2)
            {
                max3 = max2;
                max2 = element;
            }
            else if (element > max3)
            {
                max3 = element;
            }

            if (element < min1)
            {
                min2 = min1;
                min1 = element;
            }
            else if (element < min2)
            {
                min2 = element;
            }
        }

        long long prod1 = max1 * max2 * max3;
        long long prod2 = max1 * min1 * min2;

        if (prod1 > prod2)
        {
            return prod1;
        }

        return prod2;
    }
};

// } Driver Code Ends

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends