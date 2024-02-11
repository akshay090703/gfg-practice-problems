#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(int arr[], int d, int n)
    {
        int i = 0;
        int j = (n - d) % n;

        // first reverse the array from 0 to d-1
        reverse(arr, arr + (d % n));

        // then reverse array from d to n-1
        reverse(arr + (d % n), arr + n);

        // reverse the full array from 0 to n-1
        reverse(arr, arr + n);
    }
};

int main()
{

    return 0;
}