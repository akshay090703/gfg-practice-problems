//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<int> countDistinct(int A[], int n, int k)
    {
        vector<int> result;
        unordered_map<int, int> mp;
        int left = 0, right = 0;
        while (right < n)
        {
            mp[A[right]]++;

            while (right - left + 1 > k)
            {
                mp[A[left]]--;

                if (mp[A[left]] == 0)
                {
                    mp.erase(A[left]);
                }

                left++;
            }

            if (right - left + 1 == k)
                result.push_back(mp.size());

            right++;
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

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        vector<int> result = obj.countDistinct(a, n, k);
        for (int i : result)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends