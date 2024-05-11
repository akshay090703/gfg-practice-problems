//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr, int n)
    {
        vector<int> minArr;
        minArr.push_back(0);
        int mini = arr[0];

        vector<int> rightMin;
        rightMin.push_back(0);
        int minRight = arr[n - 1];

        stack<int> minSt;
        minSt.push(arr[0]);

        for (int i = 1; i < n; i++)
        {
            if (mini >= arr[i])
            {
                minArr.push_back(0);
                mini = arr[i];
                minSt.push(arr[i]);

                continue;
            }

            mini = min(mini, arr[i]);

            while (minSt.top() >= arr[i])
            {
                minSt.pop();
            }

            minArr.push_back(minSt.top());
            minSt.push(arr[i]);
        }

        stack<int> rightSt;
        rightSt.push(arr[n - 1]);

        for (int i = n - 2; i >= 0; i--)
        {
            if (minRight >= arr[i])
            {
                rightMin.push_back(0);
                minRight = arr[i];
                rightSt.push(arr[i]);

                continue;
            }

            minRight = min(minRight, arr[i]);

            while (rightSt.top() >= arr[i])
            {
                rightSt.pop();
            }

            rightMin.push_back(rightSt.top());
            rightSt.push(arr[i]);
        }

        int maxDiff = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            maxDiff = max(maxDiff, abs(minArr[i] - rightMin[(n - 1) - i]));
        }

        return maxDiff;
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
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.findMaxDiff(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends