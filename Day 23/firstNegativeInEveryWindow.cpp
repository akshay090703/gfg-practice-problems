//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                            long long int n, long long int k);

// Driver program to test above functions
int main()
{
    long long int t, i;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{

    vector<long long> ans;
    long long negativeVal = 0;
    // number and index
    queue<pair<long long, long long int>> q;

    for (int i = 0; i < K; i++)
    {
        q.push({A[i], i});
        if (A[i] < 0 and negativeVal == 0)
        {
            negativeVal = A[i];
        }
    }
    ans.push_back(negativeVal);

    int start = 1;
    for (int i = K; i < N; i++)
    {
        if (!q.empty() and q.front().second < start)
        {
            q.pop();
        }
        q.push({A[i], i});

        while (!q.empty() and q.front().first >= 0)
        {
            q.pop();
        }

        if (q.empty())
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(q.front().first);
        }

        start++;
    }

    return ans;
}