//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int distributeTicket(int N, int K)
    {
        int left = 0;
        int right = N + 1;
        bool firstK = true;

        while (left < right)
        {
            int k = K;

            if (firstK)
            {
                while (k-- and left != right - 1)
                {
                    left++;
                }

                if (left == right - 1)
                    return left;
            }
            else
            {
                while (k-- and left + 1 != right)
                {
                    right--;
                }

                if (left + 1 == right)
                    return right;
            }

            firstK = !firstK;
        }

        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        Solution obj;
        int res = obj.distributeTicket(N, K);

        cout << res << endl;
    }
}

// } Driver Code Ends