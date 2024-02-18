#include <iostream>
using namespace std;

class Solution
{
public:
    // arr: input array
    // n: size of array
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n)
    {
        long long maxSum = INT_MIN;
        long long sum = 0;
        int maxNegativeNum = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
            {
                maxNegativeNum = max(maxNegativeNum, arr[i]);
            }

            sum += arr[i];

            maxSum = max(maxSum, sum);

            if (sum < 0)
            {
                sum = 0;
            }
        }

        if (maxSum == INT_MIN)
        {
            maxSum = 0;
        }
        else if (maxSum == 0)
        {
            maxSum = maxNegativeNum;
        }

        return maxSum;
    }
};

int main()
{

    return 0;
}