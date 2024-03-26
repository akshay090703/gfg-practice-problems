//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    string convertToRoman(int n)
    {
        string roman[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int values[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

        string ans = "";
        for (int i = 12; i >= 0; i--)
        {
            while (n >= values[i])
            {
                ans += roman[i];
                n -= values[i];
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.convertToRoman(N) << endl;
    }
    return 0;
}
// } Driver Code Ends