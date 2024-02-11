#include <iostream>
using namespace std;

class Solution
{
public:
    // Function returns the second
    // largest elements
    int print2largest(int arr[], int n)
    {
        int largest = INT_MIN;
        int secondLargest = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            if (largest < arr[i])
            {
                secondLargest = largest;
                largest = arr[i];
            }
            else if (arr[i] > secondLargest && arr[i] != largest)
            {
                secondLargest = arr[i];
            }
        }

        if (largest == secondLargest or secondLargest == INT_MIN)
        {
            return -1;
        }

        return secondLargest;
    }
};

int main()
{

    return 0;
}