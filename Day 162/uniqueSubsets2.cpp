#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time Complexity -> O(2^n * n)
    void solve(vector<int> &nums, vector<vector<int>> &result, vector<int> &curr, int start)
    {
        result.push_back(curr);

        for (int i = start; i < nums.size(); i++)
        {
            if (i > start and nums[i] == nums[i - 1])
                continue;

            curr.push_back(nums[i]);
            solve(nums, result, curr, i + 1);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        solve(nums, result, curr, 0);

        return result;
    }
};

int main()
{

    return 0;
}