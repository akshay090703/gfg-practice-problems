#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minSubset(vector<int> &Arr, int N)
    {
        sort(Arr.begin(), Arr.end(), greater<int>());
        long long sum = 0;

        for (int i = 0; i < N; i++)
        {
            sum += Arr[i];
        }

        long long currSum = 0;
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            currSum += Arr[i];
            sum -= Arr[i];
            count++;

            if (currSum > sum)
            {
                break;
            }
        }

        return count;
    }
};

int main()
{

    return 0;
}