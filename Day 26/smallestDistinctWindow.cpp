//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findSubString(string str)
    {
        int n = str.length();
        int totalDistinctChars = 0;
        vector<int> occurances(256, 0);
        for (int i = 0; i < n; i++)
        {
            occurances[str[i]]++;

            if (occurances[str[i]] == 1)
            {
                totalDistinctChars++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            occurances[str[i]]--;
        }

        int start = 0;
        int min_length = INT_MAX;
        int distinct_count = 0;
        for (int end = 0; end < n; end++)
        {
            occurances[str[end]]++;

            if (occurances[str[end]] == 1)
            {
                distinct_count++;
            }

            while (distinct_count == totalDistinctChars)
            {
                occurances[str[start]]--;

                min_length = min(min_length, end - start + 1);

                if (occurances[str[start]] == 0)
                {
                    distinct_count--;
                }

                start++;
            }
        }

        return min_length;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends