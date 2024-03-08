//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    bool sameFreq(string s)
    {
        vector<int> frequency(26, 0);

        for (int i = 0; i < s.length(); i++)
        {
            frequency[s[i] - 'a']++;
        }

        int freq1 = 0, freq2 = 0, count1 = 0, count2 = 0;

        for (int i = 0; i < 26; i++)
        {
            if (frequency[i] != 0)
            {
                if (freq1 == 0)
                {
                    freq1 = frequency[i];
                    count1 = 1;
                }
                else if (freq2 == 0 and frequency[i] != freq1)
                {
                    freq2 = frequency[i];
                    count2 = 1;
                }
                else if (frequency[i] == freq1)
                {
                    count1++;
                }
                else if (frequency[i] == freq2)
                {
                    count2++;
                }
                else
                {
                    return false;
                }
            }
        }

        if (count1 == 1 and (freq1 == 1 or freq1 == freq2 + 1))
        {
            return true;
        }
        else if (count2 == 1 and (freq2 == 1 or freq2 == freq1 + 1))
        {
            return true;
        }
        else if (count1 == 0 or count2 == 0)
        {
            return true;
        }

        return false;
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
        cout << ob.sameFreq(s) << endl;
    }
}

// } Driver Code Ends