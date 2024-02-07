#include <iostream>
using namespace std;

class Solution
{
public:
    void segregate0and1(int arr[], int n)
    {
        int start = 0, end = n - 1;
        while (start <= end)
        {
            if (arr[start] == 1 && arr[end] == 0)
            {
                swap(arr[start], arr[end]);
                start++;
                end--;
            }
            else if (arr[start] == 0)
            {
                start++;
            }
            else if (arr[end] == 1)
            {
                end--;
            }
        }
    }
};

int main()
{

    return 0;
}