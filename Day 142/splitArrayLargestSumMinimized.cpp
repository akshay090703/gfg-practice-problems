#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidSubarrSum(vector<int> &nums, int n, int k, int subarrSum)
    {
        long long sum = 0;
        int count = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > subarrSum)
                return false;

            if (sum + nums[i] > subarrSum)
            {
                count++;
                sum = nums[i];

                if (count > k)
                    return false;
            }
            else
            {
                sum += nums[i];
            }
        }

        return true;
    }

    int splitArray(vector<int> &nums, int k)
    {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }

        long long start = 1, end = sum;
        int res = -1;
        while (start <= end)
        {
            long long mid = start + ((end - start) / 2);

            if (isValidSubarrSum(nums, n, k, mid))
            {
                end = mid - 1;
                res = mid;
            }
            else
            {
                start = mid + 1;
            }
        }

        return res;
    }
};

int main()
{

    return 0;
}