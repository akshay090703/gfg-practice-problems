#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long> &arr, int n, int k)
    {
        int i = 0;
        int count = 1;
        while (i < n)
        {
            int j = (k * count) - 1;
            if (j >= n)
                j = n - 1;
            while (i < j && i < n)
            {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
            i = k * count;
            count++;
        }
    }
};

int main()
{

    return 0;
}