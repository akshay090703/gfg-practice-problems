#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidDivisor(vector<int> &nums, int n, int threshold, int divisor)
    {
        long long int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += ceil((double)nums[i] / (double)divisor);
        }

        return sum <= threshold;
    }

    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int n = nums.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, nums[i]);
        }

        int start = 1, end = maxi;
        int result = -1;
        while (start <= end)
        {
            int mid = start + ((end - start) / 2);

            if (isValidDivisor(nums, n, threshold, mid))
            {
                result = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return result;
    }
};

int main()
{

    return 0;
}