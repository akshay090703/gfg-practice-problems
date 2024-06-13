#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        if (n < 4)
            return {};

        for (int i = 0; i < n; i++)
        {
            if (i != 0 and nums[i - 1] == nums[i])
                continue;

            for (int j = i + 1; j < n; j++)
            {
                if (j > i + 1 and nums[j - 1] == nums[j])
                    continue;

                int k = j + 1, l = n - 1;
                while (k < l)
                {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum > target)
                    {
                        l--;
                    }
                    else if (sum < target)
                    {
                        k++;
                    }
                    else
                    {
                        vector<int> sequence(4);
                        sequence[0] = nums[i];
                        sequence[1] = nums[j];
                        sequence[2] = nums[k];
                        sequence[3] = nums[l];
                        result.push_back(sequence);

                        k++;
                        l--;

                        while (k < l and nums[k] == nums[k - 1])
                            k++;
                        while (k < l and nums[l] == nums[l + 1])
                            l--;
                    }
                }
            }
        }

        return result;
    }
};

int main() {}