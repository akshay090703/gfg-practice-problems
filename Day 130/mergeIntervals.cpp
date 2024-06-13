#include <bits/stdc++.h>
using namespace std;

bool customCom(vector<int> &A, vector<int> &B)
{
    if (A[0] == B[0])
    {
        return A[1] > B[1];
    }

    return A[0] < B[0];
}

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        if (n < 2)
            return intervals;

        sort(intervals.begin(), intervals.end(), customCom);
        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for (int i = 1; i < n; i++)
        {
            if (result.back()[1] >= intervals[i][0])
            {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};

int main() {}