//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int countZeros(string str)
    {
        int count = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '0')
            {
                count++;
            }
        }

        return count;
    }

    string MaxZero(string a[], int n)
    {
        int maxZeros = INT_MIN;
        string maxNum = "";

        for (int i = 0; i < n; i++)
        {
            int zeros = countZeros(a[i]);

            if (maxZeros < zeros)
            {
                maxZeros = zeros;
                maxNum = a[i];
            }
            else if (maxZeros == zeros)
            {
                if ((maxNum.length() < a[i].length()) or (maxNum.length() == a[i].length() and a[i] > maxNum))
                {
                    maxNum = a[i];
                }
            }
        }

        if (maxZeros == 0)
        {
            return "-1";
        }

        return maxNum;
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
        string a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        cout << ob.MaxZero(a, n);

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends