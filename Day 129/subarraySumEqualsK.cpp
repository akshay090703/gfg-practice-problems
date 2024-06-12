#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        // sum : elements
        unordered_map<int, int> mp;
        int n = nums.size();

        long long sum = 0;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];

            if (sum == k)
                count++;

            if (mp.find(sum - k) != mp.end())
            {
                count += mp[sum - k];
            }

            mp[sum]++;
        }

        return count;
    }
};

int main() {}