#include <iostream>
using namespace std;

class Solution
{
public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n)
    {
        int i = 0;
        int j = n - 1;
        long long leftSum = 0;
        long long rightSum = 0;

        while (i < j)
        {
            leftSum += a[i];
            i++;

            while (i < j && leftSum >= rightSum)
            {
                rightSum += a[j];
                j--;
            }
        }

        if (leftSum == rightSum)
        {
            return i + 1;
        }

        return -1;
    }
};

int main()
{

    return 0;
}