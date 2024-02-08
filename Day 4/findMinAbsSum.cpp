#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    long long findMinSum(vector<int> &A, vector<int> &B, int N)
    {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        long long minSum = 0;

        for (int i = 0; i < N; i++)
        {
            minSum += abs(A[i] - B[i]);
        }

        return minSum;
    }
};

int main()
{

    return 0;
}