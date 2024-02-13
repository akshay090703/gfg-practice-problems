#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int partition(int arr[], int l, int r)
    {
        int pivot = arr[r];
        int i = l - 1;

        for (int j = l; j <= r; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[r]);
        return i + 1;
    }

    void quickSort(int arr[], int l, int r)
    {
        if (l >= r)
        {
            return;
        }

        int pivot = partition(arr, l, r);
        quickSort(arr, l, pivot - 1);
        quickSort(arr, pivot + 1, r);
    }

    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k)
    {
        quickSort(arr, l, r);
        return arr[k - 1];
    }
};

int main()
{

    return 0;
}