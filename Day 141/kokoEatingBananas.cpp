#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(vector<int> &pilas, int h, int n, int k)
    {
        long long int hours = 0;

        for (int i = 0; i < n; i++)
        {
            hours += ceil((double)pilas[i] / (double)k);
        }

        return h >= hours;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size();

        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, piles[i]);
        }

        int start = 1, end = maxi;
        int result = -1;
        while (start <= end)
        {
            int mid = start + ((end - start) / 2);

            if (isValid(piles, h, n, mid))
            {
                end = mid - 1;
                result = mid;
            }
            else
            {
                start = mid + 1;
            }
        }

        return result;
    }
};

int main()
{

    return 0;
}