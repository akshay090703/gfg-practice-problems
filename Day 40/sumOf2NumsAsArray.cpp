//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    vector<int> findSum(vector<int> &a, vector<int> &b)
    {
        int n = a.size();
        int m = b.size();
        vector<int> ans;

        int i = n - 1;
        int j = m - 1;
        int carry = 0;
        while (i >= 0 and j >= 0)
        {
            int sum = a[i] + b[j] + carry;
            carry = 0;

            if (sum > 9)
            {
                carry = sum / 10;
                sum %= 10;

                ans.push_back(sum);
            }
            else
            {
                ans.push_back(sum);
            }

            i--;
            j--;
        }

        while (i >= 0)
        {
            int sum = a[i] + carry;
            carry = 0;

            if (sum > 9)
            {
                carry = sum / 10;
                sum %= 10;

                ans.push_back(sum);
            }
            else
            {
                ans.push_back(sum);
            }

            i--;
        }

        while (j >= 0)
        {
            int sum = b[j] + carry;
            carry = 0;

            if (sum > 9)
            {
                carry = sum / 10;
                sum %= 10;

                ans.push_back(sum);
            }
            else
            {
                ans.push_back(sum);
            }

            j--;
        }

        if (carry > 0)
        {
            ans.push_back(carry);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        Solution ob;
        auto ans = ob.findSum(a, b);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends