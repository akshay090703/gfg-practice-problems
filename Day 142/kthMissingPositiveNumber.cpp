#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        int start = 0, end = n - 1;
        int res = -1;

        if (k < arr[0])
            return k;

        while (start <= end)
        {
            int mid = start + ((end - start) / 2);
            int missingUntilMid = arr[mid] - (mid + 1);

            if (missingUntilMid < k)
            {
                start = mid + 1;
                res = mid;
            }
            else
            {
                end = mid - 1;
            }
        }

        if (res == -1)
        {
            return k;
        }

        int missingUntilRes = arr[res] - (res + 1);

        return (arr[res] + (k - missingUntilRes));
    }
};

int main()
{

    return 0;
}