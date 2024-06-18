//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    vector<int> findMissing(int a[], int b[], int n, int m)
    {
        unordered_map<int, bool> isVisited;
        vector<int> result;

        for (int i = 0; i < m; i++)
        {
            isVisited[b[i]] = true;
        }

        for (int i = 0; i < n; i++)
        {
            if (isVisited.find(a[i]) == isVisited.end())
            {
                result.push_back(a[i]);
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
        int n;
        cin >> n;
        int m;
        cin >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        vector<int> ans;

        Solution ob;
        ans = ob.findMissing(a, b, n, m);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends