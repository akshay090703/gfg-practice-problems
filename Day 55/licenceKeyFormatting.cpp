//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++
class Solution
{
public:
    char customToUpper(char &ch)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            return ch - ('a' - 'A');
        }
        return ch;
    }

    bool isAlpha(char &ch)
    {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }

    std::string ReverseString(std::string &str)
    {
        std::reverse(str.begin(), str.end());
        return str;
    }

    string ReFormatString(string &S, int &K)
    {
        string ans = "";
        int groupSize = 0;
        int n = S.length();

        for (int i = n - 1; i >= 0; i--)
        {
            if (S[i] != '-')
            {
                if (groupSize == K)
                {
                    ans += '-';
                    groupSize = 0;
                }

                if (isAlpha(S[i]))
                {
                    ans += customToUpper(S[i]);
                }
                else
                {
                    ans += S[i];
                }
                groupSize++;
            }
        }

        return ReverseString(ans);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution ob;
        string ans = ob.ReFormatString(S, K);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends