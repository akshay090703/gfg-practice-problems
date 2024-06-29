//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int beautySum(string s)
    {
        int n = s.length();
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            int freq[26] = {0};

            for (int j = i; j < n; j++)
            {
                char ch = s[j];
                freq[ch - 'a']++;

                int maxFreq = INT_MIN;
                int minFreq = INT_MAX;
                for (int k = 0; k < 26; k++)
                {
                    if (freq[k] > 0)
                    {
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }

                sum += (maxFreq - minFreq);
            }
        }

        return sum;
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
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends