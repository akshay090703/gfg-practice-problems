//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int powerOfNum(int num, int n)
    {
        if (n == 0)
            return 1;
        int ans = 1;

        for (int i = 0; i < n; i++)
        {
            ans *= num;
        }

        return ans;
    }

    int DivisibleByEight(string s)
    {
        long long num = 0;
        int temp = 0;
        int j = 0;
        if (s.length() < 3)
        {
            for (int i = s.length() - 1; i >= 0; i--)
            {
                int digit = s[i] - '0'; // converting char to number
                num += digit * powerOfNum(10, j);
                j++;
            }
        }
        else
        {
            int last = s[s.length() - 1] - '0';
            int secondLast = s[s.length() - 2] - '0';
            int thirdLast = s[s.length() - 3] - '0';

            num = last + (secondLast * 10) + (thirdLast * 100);
        }

        if (num % 8 == 0)
        {
            return 1;
        }

        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.DivisibleByEight(S) << "\n";
    }
}
// } Driver Code Ends