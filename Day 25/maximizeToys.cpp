//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int toyCount(int N, int K, vector<int> arr)
    {
        sort(arr.begin(), arr.end());
        int count = 0;
        int money = 0;
        for (int i = 0; i < N; i++)
        {
            if (money + arr[i] <= K)
            {
                money += arr[i];
                count++;
            }
            else
            {
                break;
            }
        }

        return count;
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
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.toyCount(N, K, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends