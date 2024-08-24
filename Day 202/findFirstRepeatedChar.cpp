//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << firstRepChar(s) << endl;
    }
    return 0;
}
// } Driver Code Ends

string firstRepChar(string s)
{
    int n = s.length();
    vector<int> freq(26, 0);
    string result = "";

    for (int i = 0; i < n; i++)
    {
        int idx = s[i] - 'a';

        if (freq[idx] > 0)
        {
            result += s[i];
            return result;
        }

        freq[idx]++;
    }

    return "-1";
}