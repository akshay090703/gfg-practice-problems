//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    long long int sumOfArr(int arr[], int n)
    {
        long long int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        return sum;
    }

    int findSwapValues(int a[], int n, int b[], int m)
    {
        long long int sum1 = sumOfArr(a, n), sum2 = sumOfArr(b, m);

        sort(a, a + n);
        sort(b, b + m);

        int i = 0, j = 0;
        while (i < n and j < m)
        {
            long long int sumWithoutI = sum1 - a[i] + b[j];
            long long int sumWithoutJ = sum2 - b[j] + a[i];

            if (sumWithoutI > sumWithoutJ)
            {
                i++;
            }
            else if (sumWithoutI < sumWithoutJ)
            {
                j++;
            }
            else
            {
                return 1;
            }
        }

        return -1;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends