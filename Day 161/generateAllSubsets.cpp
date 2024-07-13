#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<int> &nums, vector<vector<int>> &result, vector<int> subset, int i)
    {
        if (i == nums.size())
        {
            result.push_back(subset);
            return;
        }

        solve(nums, result, subset, i + 1);

        subset.push_back(nums[i]);
        solve(nums, result, subset, i + 1);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        solve(nums, result, {}, 0);

        return result;
    }
};

int main()
{

    return 0;
}