//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string calc_Sum(int *a, int n, int *b, int m)
    {
        string ans = "";

        int carry = 0;
        int i = n - 1, j = m - 1;
        while (i >= 0 and j >= 0)
        {
            int sum = a[i] + b[j] + carry;
            carry = 0;

            if (sum > 9)
            {
                carry = sum / 10;
                sum = sum % 10;
            }

            char digit = '0' + sum;
            ans = digit + ans;

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
                sum = sum % 10;
            }

            char digit = '0' + sum;
            ans = digit + ans;

            i--;
        }

        while (j >= 0)
        {
            int sum = b[j] + carry;
            carry = 0;

            if (sum > 9)
            {
                carry = sum / 10;
                sum = sum % 10;
            }

            char digit = '0' + sum;
            ans = digit + ans;

            j--;
        }

        if (carry > 0)
        {
            char digit = '0' + carry;
            ans = digit + ans;
        }

        while (ans[0] == '0')
        {
            ans.erase(0, 1);
        }

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
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int m;
        cin >> m;
        int b[m];
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        Solution ob;
        cout << ob.calc_Sum(a, n, b, m) << endl;
    }
    return 0;
}
// } Driver Code Ends