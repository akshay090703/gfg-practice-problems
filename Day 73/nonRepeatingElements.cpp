//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
        unordered_map<char, pair<int, int>> chars;
        int length = S.length();

        for (int i = 0; i < length; i++)
        {
            pair<int, int> p = chars[S[i]];
            chars[S[i]] = {p.first + 1, i + 1};
        }

        pair<int, int> p = {1, INT_MAX};
        char ans = '$';
        for (auto i = chars.begin(); i != chars.end(); i++)
        {
            if (i->second.first == 1)
            {
                if (p.second > i->second.second)
                {
                    p.second = i->second.second;
                    ans = i->first;
                }
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    int T;
    cin >> T;

    while (T--)
    {

        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonrepeatingCharacter(S);

        if (ans != '$')
            cout << ans;
        else
            cout << "-1";

        cout << endl;
    }

    return 0;
}

// } Driver Code Ends