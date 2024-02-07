#include <iostream>
using namespace std;

class Solution
{
public:
    void pushZerosToEnd(int arr[], int n)
    {
        int count = 0; // Count of non-zero elements

        // Traverse the array and move non-zero elements to the front
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 0)
            {
                arr[count++] = arr[i];
            }
        }

        // Fill the remaining elements with zeros
        while (count < n)
        {
            arr[count++] = 0;
        }
    }
};

int main()
{

    return 0;
}