//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    const char hexadecimal[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    string toHexadecimal(int num)
    {
        string ans = "";

        while (num != 0)
        {
            int rem = num % 16;
            ans += hexadecimal[rem];

            num = num / 16;
        }

        return ans;
    }

    string encryptString(string S)
    {

        int repeatingElements = 1;
        string ans = "";
        for (int i = 0; i < S.length(); i++)
        {
            char element = S[i];

            while (i + 1 < S.length() and S[i] == S[i + 1])
            {
                repeatingElements++;
                i++;
            }

            ans += element;
            if (repeatingElements >= 1 && repeatingElements <= 15)
                ans += hexadecimal[repeatingElements];
            else if (repeatingElements > 15)
                ans += toHexadecimal(repeatingElements);
            repeatingElements = 1;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.encryptString(S) << endl;
    }
    return 0;
}
// } Driver Code Ends