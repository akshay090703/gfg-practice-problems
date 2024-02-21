//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to check if a string can be obtained by rotating
    // another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        long long n = str1.length();
        long long m = str2.length();

        if (n != m)
            return false;

        if (str1[0] == str2[m - 2] and str1[1] == str2[m - 1] and str1[2] == str2[0])
        {
            for (long long i = 0; i < m - 2; i++)
            {
                if (str2[i] != str1[i + 2])
                {
                    return false;
                }
            }

            return true;
        }
        else if (str1[n - 1] == str2[1] and str1[n - 2] == str2[0] and str1[0] == str2[2])
        {
            for (long long i = 0; i < n - 2; i++)
            {
                if (str1[i] != str2[i + 2])
                {
                    return false;
                }
            }

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
        string b;
        cin >> s >> b;
        Solution obj;
        cout << obj.isRotated(s, b) << endl;
    }
    return 0;
}

// } Driver Code Ends