#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int breakingPoint = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                breakingPoint = i;
                break;
            }
        }

        if (breakingPoint == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        int nextLargest = INT_MAX;
        for (int i = n - 1; i > breakingPoint; i--)
        {
            if (nums[breakingPoint] < nums[i])
            {
                swap(nums[breakingPoint], nums[i]);
                break;
            }
        }

        reverse(nums.begin() + breakingPoint + 1, nums.end());
    }
};

int main()
{
}