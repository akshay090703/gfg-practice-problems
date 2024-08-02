//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // TC -> O(n) + O(n)
    // SC -> O(n)
    long long solve(long long arr[], int n)
    {
        stack<long long> st;

        long long maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and arr[st.top()] > arr[i])
            {
                long long height = arr[st.top()];
                st.pop();

                long long nse = i;
                long long pse = st.empty() ? -1 : st.top();

                long long width = nse - pse - 1;

                long long area = height * width;

                maxArea = max(maxArea, area);
            }

            st.push(i);
        }

        while (!st.empty())
        {
            long long height = arr[st.top()];
            st.pop();

            long long nse = n;
            long long pse = st.empty() ? -1 : st.top();

            long long width = nse - pse - 1;

            long long area = height * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    // Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        return solve(arr, n);
    }
};

//{ Driver Code Starts.

int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends