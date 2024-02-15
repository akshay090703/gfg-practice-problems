#include <iostream>
using namespace std;

class Solution
{
public:
    int peakElement(int arr[], int n)
    {
        int start = 0;
        int end = n - 1;

        while (start <= end)
        {
            int mid = start + ((end - start) / 2);

            if (mid == n - 1)
            {
                if (arr[mid] >= arr[mid - 1])
                {
                    return mid;
                }
            }
            else if (arr[mid] >= arr[mid - 1] and arr[mid] >= arr[mid + 1])
            {
                return mid;
            }
            else if (arr[mid] < arr[mid + 1])
            {
                start = mid + 1;
            }
            else if (arr[mid] < arr[mid - 1])
            {
                end = mid - 1;
            }
        }

        return -1;
    }
};

int main()
{

    return 0;
}