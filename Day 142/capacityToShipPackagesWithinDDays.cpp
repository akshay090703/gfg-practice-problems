#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidCapacity(vector<int> &weights, int n, int days, int capacity)
    {
        int daysNeeded = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (weights[i] > capacity)
                return false;

            if (sum + weights[i] > capacity)
            {
                daysNeeded++;
                sum = 0;
            }

            sum += weights[i];
        }

        if (sum != 0)
            daysNeeded++;

        return daysNeeded <= days;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int n = weights.size();
        long long int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += weights[i];
        }

        int start = 1, end = sum;
        int capacity = -1;
        while (start <= end)
        {
            int mid = start + ((end - start) / 2);

            if (isValidCapacity(weights, n, days, mid))
            {
                end = mid - 1;
                capacity = mid;
            }
            else
            {
                start = mid + 1;
            }
        }

        return capacity;
    }
};

int main()
{

    return 0;
}