#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time Complexity-> O(2^n * k)
    // Space Complexity-> O(n * k)
    void solve(vector<int> &candidates, vector<vector<int>> &result, vector<int> &curr, int target, int i)
    {
        if (target < 0)
            return;

        if (i == candidates.size())
        {
            if (target == 0)
            {
                result.push_back(curr);
            }

            return;
        }

        if (candidates[i] <= target)
        {
            curr.push_back(candidates[i]);
            solve(candidates, result, curr, target - candidates[i], i);
            curr.pop_back();
        }

        solve(candidates, result, curr, target, i + 1);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> curr;
        solve(candidates, result, curr, target, 0);

        return result;
    }
};

int main()
{

    return 0;
}