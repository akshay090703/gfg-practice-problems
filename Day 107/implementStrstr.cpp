//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int strstr(string, string);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        string b;

        cin >> a;
        cin >> b;

        cout << strstr(a, b) << endl;
    }
}

// } Driver Code Ends

// Function to locate the occurrence of the string x in the string s.
bool check(int i, string s, string x)
{
    for (int k = 0; k < x.length(); k++)
    {
        if (s[i + k] != x[k])
            return false;
    }
    return true;
}

int strstr(string s, string x)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == x[0])
        {
            if (check(i, s, x))
                return i;
        }
    }
    return -1;
}