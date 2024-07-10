//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<string> generateBinaryStrings(int num)
    {
        if (num == 0)
            return {};
        if (num == 1)
            return {"0", "1"};

        vector<string> result;
        for (auto str : generateBinaryStrings(num - 1))
        {
            result.push_back(str + "0");

            if (str[str.length() - 1] != '1')
            {
                result.push_back(str + "1");
            }
        }

        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t = 1;
    cin >> t;

    while (t--)
    {
        // Input
        int n;
        cin >> n;

        Solution obj;

        vector<string> v = obj.generateBinaryStrings(n);
        for (auto it : v)
            cout << it << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends