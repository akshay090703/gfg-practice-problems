//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int maxIndexDiff(int arr[], int n)
    {
        vector<int> mini(n);
        vector<int> maxi(n);

        mini[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            mini[i] = min(arr[i], mini[i - 1]);
        }

        maxi[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            maxi[i] = max(arr[i], maxi[i + 1]);
        }

        int result = 0;
        int i = 0, j = 0;
        while (i < n and j < n)
        {
            if (mini[i] <= maxi[j])
            {
                result = max(result, j - i);
                j++;
            }
            else
            {
                i++;
            }
        }

        return result;
    }
};

//{ Driver Code Starts.

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
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends