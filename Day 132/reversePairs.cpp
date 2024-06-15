#include <bits/stdc++.h>
using namespace std;

// My code
class Solution
{
public:
    int merge(vector<int> &nums, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low, right = mid + 1;
        int count = 0;

        for (int i = left; i <= mid; i++)
        {
            while (right <= high and (nums[i] > ((long long)2 * nums[right])))
            {
                right++;
            }

            count += (right - (mid + 1));
        }

        left = low, right = mid + 1;
        while (left <= mid and right <= high)
        {
            if (nums[left] <= nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else
            {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while (left <= mid)
        {
            temp.push_back(nums[left]);
            left++;
        }

        while (right <= high)
        {
            temp.push_back(nums[right]);
            right++;
        }

        for (int i = low; i <= high; i++)
        {
            nums[i] = temp[i - low];
        }

        return count;
    }

    int mergeSort(vector<int> &nums, int low, int high)
    {
        int count = 0;
        if (low >= high)
            return count;

        int mid = low + ((high - low) / 2);
        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += merge(nums, low, mid, high);

        return count;
    }

    int reversePairs(vector<int> &nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

int main() {}