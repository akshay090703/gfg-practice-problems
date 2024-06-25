//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool isValidMaxDist(vector<int> &stations, int n, int k, long double maxDist)
    {
        int station = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int numsInBetween = (int)((stations[i + 1] - stations[i]) / maxDist);

            if ((stations[i + 1] - stations[i]) == (numsInBetween * maxDist))
                numsInBetween--;

            station += numsInBetween;

            if (station > k)
                return false;
        }

        return true;
    }

    double findSmallestMaxDist(vector<int> &stations, int k)
    {
        long double maxDiff = INT_MIN;
        int n = stations.size();
        for (int i = 0; i < n - 1; i++)
        {
            maxDiff = max(maxDiff, (long double)(stations[i + 1] - stations[i]));
        }

        if (k == 0)
            return (long double)maxDiff;

        long double start = 0, end = maxDiff;
        long double result = maxDiff;
        long double precision = 1e-6;
        while ((end - start) > precision)
        {
            long double mid = (start + end) / 2.0;

            if (isValidMaxDist(stations, n, k, mid))
            {
                end = mid;
                result = mid;
            }
            else
            {
                start = mid;
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
        vector<int> stations(n);
        for (int i = 0; i < n; i++)
        {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends