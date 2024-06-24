#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int start = 0, end = n - 1;

        if (n == 1)
            return nums[0];

        while (start <= end)
        {
            int mid = start + ((end - start) / 2);

            if ((mid == 0 and nums[mid] != nums[mid + 1]) or (mid == n - 1 and nums[mid - 1] != nums[mid]))
                return nums[mid];

            if (mid != 0 and mid != n - 1 and nums[mid] != nums[mid + 1] and nums[mid - 1] != nums[mid])
                return nums[mid];

            if (mid % 2 == 0)
            {
                if (nums[mid] == nums[mid + 1])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            else
            {
                if (nums[mid] == nums[mid - 1])
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