//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    bool areKAnagrams(string str1, string str2, int k)
    {
        if (str1.length() != str2.length())
            return false;

        vector<int> freq(26, 0);

        for (char c : str1)
            freq[c - 'a']++;

        for (char c : str2)
            freq[c - 'a']--;

        int diff = 0;

        for (int f : freq)
            diff += abs(f);

        return diff <= 2 * k;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str1, str2;
        cin >> str1 >> str2;
        int k;
        cin >> k;
        Solution ob;
        if (ob.areKAnagrams(str1, str2, k) == true)
            cout << "1\n";
        else
            cout << "0\n";
    }
}
// } Driver Code Ends