//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string roundToNearest(string N)
    {
        int n = N.length();

        int lastDigit = N[n - 1] - '0';

        if (lastDigit <= 5)
        {
            N[n - 1] = '0';
        }
        else
        {
            N[n - 1] = '0';

            int i = n - 2;
            while (i >= 0 && N[i] == '9')
            {
                N[i] = '0';
                i--;
            }

            if (i >= 0)
            {
                N[i] = N[i] + 1;
            }
            else
            {
                N = '1' + N;
            }
        }

        return N;
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
        cin >> s;
        Solution ob;
        cout << ob.roundToNearest(s) << endl;
    }

    return 0;
}
// } Driver Code Ends