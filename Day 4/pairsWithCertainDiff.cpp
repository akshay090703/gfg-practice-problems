#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        sort(arr, arr + N);
        int maxSum = 0;

        int i = N - 1;
        while (i > 0)
        {
            int diff = arr[i] - arr[i - 1];
            if (diff < K)
            {
                maxSum += arr[i] + arr[i - 1];
                i--;
            }
            i--;
        }

        return maxSum;
    }
};

int main()
{

    return 0;
}