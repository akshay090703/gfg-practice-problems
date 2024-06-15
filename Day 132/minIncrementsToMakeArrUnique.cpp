#include <bits/stdc++.h>
using namespace std;

// My Approach
class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int increments = 0;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] <= nums[i - 1])
            {
                increments += nums[i - 1] - nums[i] + 1;
                nums[i] += nums[i - 1] - nums[i] + 1;
            }
        }

        return increments;
    }
};

int main() {}