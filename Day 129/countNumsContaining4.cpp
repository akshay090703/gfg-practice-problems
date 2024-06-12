//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool is4(int n)
    {
        while (n > 0)
        {
            if (n % 10 == 4)
            {
                return 1;
            }

            n /= 10;
        }

        return 0;
    }

    int countNumberswith4(int n)
    {
        int count = 0;
        for (int i = 4; i <= n; i++)
        {
            if (is4(i))
            {
                count++;
            }
        }

        return count;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends