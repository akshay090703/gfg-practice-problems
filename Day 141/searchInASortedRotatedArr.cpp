#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // My Solution

    // int rotationPoint(vector<int> &nums)
    // {
    //     int start = 0;
    //     int end = nums.size() - 1;
    //     int firstEl = nums[0];
    //     int res = -1;

    //     while (start <= end)
    //     {
    //         int mid = start + ((end - start) / 2);

    //         if (nums[mid] >= firstEl)
    //         {
    //             start = mid + 1;
    //         }
    //         else
    //         {
    //             end = mid - 1;
    //             res = mid;
    //         }
    //     }

    //     return res;
    // }

    // int binarySearch(vector<int> &nums, int target, int start, int end)
    // {
    //     while (start <= end)
    //     {
    //         int mid = start + ((end - start) / 2);

    //         if (nums[mid] > target)
    //         {
    //             end = mid - 1;
    //         }
    //         else if (nums[mid] < target)
    //         {
    //             start = mid + 1;
    //         }
    //         else
    //         {
    //             return mid;
    //         }
    //     }

    //     return -1;
    // }

    // int search(vector<int> &nums, int target)
    // {
    //     int n = nums.size();
    //     int transitionPoint = rotationPoint(nums);

    //     if (transitionPoint == -1)
    //     {
    //         return binarySearch(nums, target, 0, n - 1);
    //     }

    //     if (nums[transitionPoint] <= target and target <= nums[n - 1])
    //     {
    //         return binarySearch(nums, target, transitionPoint, n - 1);
    //     }

    //     return binarySearch(nums, target, 0, transitionPoint - 1);
    // }

    // Even more optimized solution
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int start = 0, end = n - 1;

        while (start <= end)
        {
            int mid = start + ((end - start) / 2);

            if (nums[mid] == target)
            {
                return mid;
            }

            // means start to mid portion is sorted
            if (nums[start] <= nums[mid])
            {
                if (nums[start] <= target and target <= nums[mid])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            // means mid to end portion is sorted
            else
            {
                if (nums[mid] <= target and target <= nums[end])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main()
{

    return 0;
}