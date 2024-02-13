#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findTwoElement(vector<int> arr, int n)
    {
        vector<int> ans(2);

        // Cyclic sort to find the repeating element
        int i = 0;
        while (i < n)
        {
            if (arr[i] != arr[arr[i] - 1])
            {
                swap(arr[i], arr[arr[i] - 1]);
            }
            else
            {
                i++;
            }
        }

        // Find the missing and repeating elements
        // first is repeating and second is missing number in output
        for (int j = 0; j < n; j++)
        {
            if (arr[j] != j + 1)
            {
                ans[0] = arr[j]; // means this is the repeating element
                ans[1] = j + 1;  // and this means that j+1 is missing as it is not at its correct position
                break;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}