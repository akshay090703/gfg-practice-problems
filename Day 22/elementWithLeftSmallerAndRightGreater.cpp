//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++)
            cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends

int findElement(int arr[], int n)
{
    if (n < 3)
    {
        return -1;
    }

    int maxi = INT_MIN;
    vector<int> leftMax;
    leftMax.push_back(INT_MAX);
    for (int i = 1; i < n; i++)
    {
        maxi = max(maxi, arr[i - 1]);
        leftMax.push_back(maxi);
    }

    int mini = INT_MAX;
    vector<int> rightMin(n);
    rightMin[n - 1] = INT_MIN;
    for (int i = n - 2; i >= 0; i--)
    {
        mini = min(mini, arr[i + 1]);
        rightMin[i] = mini;
    }

    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] >= leftMax[i] and arr[i] <= rightMin[i])
        {
            return arr[i];
        }
    }

    return -1;
}