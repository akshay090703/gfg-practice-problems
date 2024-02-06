#include <iostream>
#include <vector>
using namespace std;

vector<int> subarraySum(vector<int> &arr, int N, int S)
{
    int left = 0, right = 0;
    int currentSum = 0;

    while (right < N)
    {
        currentSum += arr[right];

        while (currentSum > S && left < right)
        {
            currentSum -= arr[left];
            left++;
        }

        if (currentSum == S)
        {
            return {left + 1, right + 1};
        }

        right++;
    }

    // No subarray found
    return {-1};
}

int main()
{

    return 0;
}