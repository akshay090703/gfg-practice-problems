#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        sort(a, a + n);
        int i = 0;
        while (a[i] < 0 && i < k)
        {
            a[i] *= -1;
            i++;
        }

        if (i >= k)
        {
            long long int maxSum = 0;
            for (int i = 0; i < n; i++)
            {
                maxSum += a[i];
            }
            return maxSum;
        }

        sort(a, a + n);
        while (i < k)
        {
            a[0] *= -1;
            i++;
        }

        long long int maxSum = 0;
        for (int i = 0; i < n; i++)
        {
            maxSum += a[i];
        }
        return maxSum;
    }
};

int main()
{

    return 0;
}