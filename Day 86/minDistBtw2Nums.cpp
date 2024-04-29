//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int minDist(int a[], int n, int x, int y)
    {
        int minDist = INT_MAX;
        int lastSeen = -1;

        for (int i = 0; i < n; i++)
        {
            if (a[i] == x or a[i] == y)
            {
                if (lastSeen != -1 and a[i] != a[lastSeen])
                {
                    minDist = min(minDist, i - lastSeen);
                }

                lastSeen = i;
            }
        }

        return minDist == INT_MAX ? -1 : minDist;
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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends