//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    long long maxDiamonds(int A[], int N, int K)
    {
        priority_queue<int> pq;

        for (int i = 0; i < N; i++)
        {
            pq.push(A[i]);
        }

        long long diamonds = 0;

        while (K--)
        {
            int top = pq.top();
            pq.pop();

            diamonds += top;
            top = top / 2;

            pq.push(top);
        }

        return diamonds;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;

        cin >> N >> K;
        int A[N];

        for (int i = 0; i < N; i++)
            cin >> A[i];

        Solution ob;
        cout << ob.maxDiamonds(A, N, K) << endl;
    }
    return 0;
}
// } Driver Code Ends