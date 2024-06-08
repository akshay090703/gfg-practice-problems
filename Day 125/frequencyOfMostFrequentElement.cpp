#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        int left = 0, right = 0;
        long long int sum = 0;
        int maxFreq = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        while (left < n and right < n)
        {
            sum += nums[right];
            long long windowSize = right - left + 1;
            long long value = static_cast<long long>(nums[right]) * windowSize;

            while (value > sum + k)
            {
                sum -= nums[left];
                left++;
                windowSize = right - left + 1;
                value = static_cast<long long>(nums[right]) * windowSize;
            }

            maxFreq = max(maxFreq, static_cast<int>(windowSize));
            right++;
        }

        return maxFreq;
    }
};

int main()
{
}