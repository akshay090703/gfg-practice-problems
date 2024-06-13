#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i <= n - 3; i++)
        {
            while (i != 0 and i < n - 1 and nums[i - 1] == nums[i])
                i++;

            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum > 0)
                {
                    k--;
                }
                else if (sum < 0)
                {
                    j++;
                }
                else
                {
                    vector<int> combination(3);
                    combination[0] = nums[i];
                    combination[1] = nums[j];
                    combination[2] = nums[k];

                    result.push_back(combination);

                    j++;
                    k--;

                    while (j < k and nums[j] == nums[j - 1])
                        j++;
                    while (j < k and nums[k] == nums[k + 1])
                        k--;
                }
            }
        }

        return result;
    }
};

int main() {}