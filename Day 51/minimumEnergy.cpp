//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int minEnergy(int a[], int n)
    {
        int maxNegative = INT_MIN;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];

            if (sum < 1)
            {
                if (abs(maxNegative) < abs(sum))
                {
                    maxNegative = sum;
                }
            }
        }

        if (maxNegative == INT_MIN)
            return 1;

        return abs(maxNegative) + 1;
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
        int i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minEnergy(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends