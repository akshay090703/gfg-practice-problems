#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<int> &candidates, vector<vector<int>> &result, vector<int> &curr, int start, int target)
    {
        if (target == 0)
        {
            result.push_back(curr);
            return;
        }

        for (int i = start; i < candidates.size(); i++)
        {
            if (i > start and candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                return;

            curr.push_back(candidates[i]);
            solve(candidates, result, curr, i + 1, target - candidates[i]);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> curr;
        solve(candidates, result, curr, 0, target);

        return result;
    }
};

int main()
{

    return 0;
}