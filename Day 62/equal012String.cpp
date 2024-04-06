//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    long long getSubstringWithEqual012(string str)
    {
        long long n = str.length();
        long long count0 = 0, count1 = 0, count2 = 0;
        long long ans = 0;
        unordered_map<string, int> freq;

        for (long long i = 0; i < n; i++)
        {
            if (str[i] == '0')
            {
                count0++;
            }
            else if (str[i] == '1')
            {
                count1++;
            }
            else
            {
                count2++;
            }

            int minFreq = min(count0, min(count1, count2));
            string diff = to_string(count0 - minFreq) + " " + to_string(count1 - minFreq) + " " + to_string(count2 - minFreq);

            if (freq.find(diff) != freq.end())
            {
                ans += freq[diff];
            }

            if (count0 == count1 && count1 == count2)
            {
                ans++;
            }

            freq[diff]++;
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
        string s;
        cin >> s;
        Solution ob;
        cout << ob.getSubstringWithEqual012(s) << endl;
    }
    return 0;
}

// } Driver Code Ends