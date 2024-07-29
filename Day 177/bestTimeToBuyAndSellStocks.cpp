#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        int mini = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < n; i++)
        {
            maxProfit = max(maxProfit, prices[i] - mini);
            mini = min(mini, prices[i]);
        }

        return maxProfit;
    }
};

int main()
{

    return 0;
}