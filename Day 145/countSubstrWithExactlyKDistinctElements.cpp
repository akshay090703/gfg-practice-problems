//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // here we are calculating the number of substrings with at most K unique chars (<= k distinct chars)
    long long int atMostK(string &s, int k)
    {
        int n = s.length();

        int charCount[26] = {0};
        long long count = 0;
        int left = 0;
        int distinct = 0;
        for (int right = 0; right < n; right++)
        {
            if (charCount[s[right] - 'a'] == 0)
            {
                distinct++;
            }

            charCount[s[right] - 'a']++;

            while (distinct > k)
            {
                charCount[s[left] - 'a']--;

                if (charCount[s[left] - 'a'] == 0)
                {
                    distinct--;
                }

                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }

    long long int substrCount(string &s, int k)
    {
        // (at most k unique chars) - (at most k - 1 unique chars) = exactly k distinct characters
        return atMostK(s, k) - atMostK(s, k - 1);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.substrCount(s, k) << endl;
    }
}
// } Driver Code Ends