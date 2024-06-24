#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isDaysPossible(vector<int> &bloomDay, int n, int days, int m, int k)
    {
        int count = 0;
        int noOfBouquets = 0;
        for (int i = 0; i < n; i++)
        {
            if (bloomDay[i] <= days)
            {
                count++;
            }
            else
            {
                // because we need adjacent flowers to make a bouquet
                noOfBouquets += (count / k);
                count = 0;
            }
        }

        noOfBouquets += (count / k);

        return noOfBouquets >= m;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();

        long long int flowersReq = (long long)m * (long long)k;
        if (flowersReq > n)
            return -1;

        int maxDays = INT_MIN;
        int minDays = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            maxDays = max(maxDays, bloomDay[i]);
            minDays = min(minDays, bloomDay[i]);
        }

        int start = minDays, end = maxDays;
        int minDaysReq = -1;
        while (start <= end)
        {
            int mid = start + ((end - start) / 2);

            if (isDaysPossible(bloomDay, n, mid, m, k))
            {
                end = mid - 1;
                minDaysReq = mid;
            }
            else
            {
                start = mid + 1;
            }
        }

        return minDaysReq;
    }
};

int main()
{

    return 0;
}