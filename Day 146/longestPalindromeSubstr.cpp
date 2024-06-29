//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    string expandAroundCenter(string &S, int left, int right, int n)
    {
        while (left >= 0 and right < n and S[left] == S[right])
        {
            left--;
            right++;
        }

        left++;
        right--;

        return S.substr(left, right - left + 1);
    }

    string longestPalindrome(string S)
    {
        int n = S.length();

        int max_count = 0;
        string longestSubstr = "";
        for (int i = 0; i < n; i++)
        {
            // as we are finding odd palindrome so only 1 center
            string oddPalindromeStr = expandAroundCenter(S, i, i, n);
            if (oddPalindromeStr.length() > max_count)
            {
                longestSubstr = oddPalindromeStr;
            }

            // now in an even length palindrom, there always are 2 centers that are equal
            string evenPalindromeStr = expandAroundCenter(S, i, i + 1, n);
            if (evenPalindromeStr.length() > max_count)
            {
                longestSubstr = evenPalindromeStr;
            }

            max_count = longestSubstr.length();
        }

        return longestSubstr;
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
        cout << ob.longestPalindrome(S) << endl;
    }
    return 0;
}

// } Driver Code Ends