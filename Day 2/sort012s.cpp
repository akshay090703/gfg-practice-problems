#include <iostream>
using namespace std;

class Solution
{
public:
    void sort012(int a[], int n)
    {
        int left = 0, middle = 0, right = n - 1;

        while (middle <= right)
        {
            if (a[middle] == 0)
            {
                swap(a[left], a[middle]);
                left++;
                middle++;
            }
            else if (a[middle] == 1)
            {
                middle++;
            }
            else if (a[middle] == 2)
            {
                swap(a[right], a[middle]);
                right--;
            }
        }
    }
};

int main()
{

    return 0;
}