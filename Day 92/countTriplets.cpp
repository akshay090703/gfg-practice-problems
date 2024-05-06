//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int countTriplet(int arr[], int n)
    {
        sort(arr, arr + n);

        if (n < 3)
            return 0;

        int count = 0;
        int thirdIdx = n - 1;

        while (thirdIdx > 1)
        {
            int start = 0;
            int end = thirdIdx - 1;

            while (start < end)
            {
                int sum = arr[start] + arr[end];

                if (sum == arr[thirdIdx])
                {
                    count++;

                    start++;
                    end--;
                }
                else if (sum < arr[thirdIdx])
                {
                    start++;
                }
                else
                {
                    end--;
                }
            }

            thirdIdx--;
        }

        return count;
    }
};

//{ Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";
    }

    return 0;
}
// } Driver Code Ends