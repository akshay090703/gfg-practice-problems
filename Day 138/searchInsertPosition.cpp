#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;

        if (nums[start] > target)
            return 0;
        if (nums[end] < target)
            return end + 1;

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
                return mid;
            }
        }

        if (nums[end] > target)
            return end;

        return end + 1;
    }
};

int main()
{

    return 0;
}