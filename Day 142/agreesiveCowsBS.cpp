//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool isValidDistance(vector<int> &stalls, int n, int k, int distance)
    {
        int assignedCows = 1;
        int lastAssigned = stalls[0];
        for (int i = 1; i < n; i++)
        {
            if (abs(stalls[i] - lastAssigned) >= distance)
            {
                assignedCows++;
                lastAssigned = stalls[i];

                if (assignedCows == k)
                    return true;
            }
        }

        return false;
    }

    int solve(int n, int k, vector<int> &stalls)
    {
        sort(stalls.begin(), stalls.end());
        int res = -1;

        long long start = 1, end = stalls[n - 1];
        while (start <= end)
        {
            int mid = start + ((end - start) / 2);

            if (isValidDistance(stalls, n, k, mid))
            {
                res = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--)
    {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++)
        {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends