#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstOcc(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        int result = -1;

        while (start <= end)
        {
            int mid = start + ((end - start) / 2);

            if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                result = mid;
                end = mid - 1;
            }
        }

        return result;
    }

    int lastOcc(vector<int> &nums, int target)
    {
        int start = 0, end = nums.size() - 1, result = -1;

        while (start <= end)
        {
            int mid = start + ((end - start) / 2);

            if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                result = mid;
                start = mid + 1;
            }
        }

        return result;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        return {firstOcc(nums, target), lastOcc(nums, target)};
    }
};

int main()
{

    return 0;
}