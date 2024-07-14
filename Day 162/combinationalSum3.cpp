#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<int> &nums, vector<vector<int>> &result, vector<int> &curr, int k, int n, int i)
    {
        if (curr.size() == k)
        {
            if (n == 0)
                result.push_back(curr);
            return;
        }

        if (n < 0 or i == 9)
            return;

        curr.push_back(nums[i]);
        solve(nums, result, curr, k, n - nums[i], i + 1);

        curr.pop_back();
        solve(nums, result, curr, k, n, i + 1);
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        vector<vector<int>> result;
        vector<int> curr;
        solve(nums, result, curr, k, n, 0);

        return result;
    }
};

int main()
{

    return 0;
}