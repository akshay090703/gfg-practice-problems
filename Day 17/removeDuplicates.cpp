//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    string removeDups(string S)
    {
        vector<int> charFreq(26, 0);
        string result;

        for (char ch : S)
        {
            if (charFreq[ch - 'a'] == 0)
            {
                result += ch;
                charFreq[ch - 'a'] = 1;
            }
        }

        return result;
    }
};

//{ Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends