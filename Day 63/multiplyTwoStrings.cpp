//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string multiplyStrings(string s1, string s2)
    {
        bool isNegative = false;
        if (s1[0] == '-')
        {
            isNegative = !isNegative;
            s1 = s1.substr(1);
        }

        if (s2[0] == '-')
        {
            isNegative = !isNegative;
            s2 = s2.substr(1);
        }

        int n = s1.length();
        int m = s2.length();
        string result(n + m, '0');

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int mul = (s1[i] - '0') * (s2[j] - '0');
                int sum = mul + (result[i + j + 1] - '0');

                result[i + j + 1] = (sum % 10) + '0';
                result[i + j] += sum / 10;
            }
        }

        int i = 0;
        while (i < n + m && result[i] == '0')
        {
            i++;
        }

        if (i == n + m)
        {
            return "0";
        }

        if (isNegative)
            return "-" + result.substr(i);

        return result.substr(i);
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string a;
        string b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;
    }
}
// } Driver Code Ends