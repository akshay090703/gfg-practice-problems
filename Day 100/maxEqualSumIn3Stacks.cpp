//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    long long int sumOfStack(vector<int> &a, int n)
    {
        long long int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += a[i];
        }

        return sum;
    }

    int maxEqualSum(int N1, int N2, int N3, vector<int> &S1, vector<int> &S2, vector<int> &S3)
    {
        long long int sum1 = sumOfStack(S1, N1);
        long long int sum2 = sumOfStack(S2, N2);
        long long int sum3 = sumOfStack(S3, N3);

        int i = 0, j = 0, k = 0;

        while (i < N1 and j < N2 and k < N3)
        {
            if (sum1 == sum2 and sum2 == sum3)
            {
                return sum1;
            }

            if (sum1 >= sum2 and sum1 >= sum3)
            {
                sum1 -= S1[i++];
            }
            else if (sum2 >= sum1 and sum2 >= sum3)
            {
                sum2 -= S2[j++];
            }
            else if (sum3 >= sum1 and sum3 >= sum2)
            {
                sum3 -= S3[k++];
            }
        }

        return 0;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        vector<int> s1(n1), s2(n2), s3(n3);
        for (int i = 0; i < n1; i++)
        {
            cin >> s1[i];
        }
        for (int i = 0; i < n2; i++)
        {
            cin >> s2[i];
        }
        for (int i = 0; i < n3; i++)
        {
            cin >> s3[i];
        }
        Solution ob;
        int ans = ob.maxEqualSum(n1, n2, n3, s1, s2, s3);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends