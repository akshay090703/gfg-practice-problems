//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends

pair<int, int> getFloorAndCeil(int arr[], int n, int x)
{
    pair<int, int> result = {INT_MIN, INT_MAX};

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return {arr[i], arr[i]};
        }

        if (arr[i] < x)
        {
            result.first = max(result.first, arr[i]);
        }
        else
        {
            result.second = min(result.second, arr[i]);
        }
    }

    if (result.first == INT_MIN)
        result.first = -1;
    if (result.second == INT_MAX)
        result.second = -1;

    return result;
}