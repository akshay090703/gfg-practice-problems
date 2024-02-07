#include <iostream>
using namespace std;

class Solution
{
public:
    int findExtra(int a[], int b[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (!binarySearch(b, a[i], n))
            {
                return i;
            }
        }

        return -1;
    }

    bool binarySearch(int arr[], int target, int n)
    {
        int start = 0;
        int end = n - 1;
        while (start <= end)
        {
            int mid = start + ((end - start) / 2);
            if (arr[mid] < target)
            {
                start = mid + 1;
            }
            else if (arr[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{

    return 0;
}