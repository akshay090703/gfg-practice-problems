#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void rearrange(int arr[], int n)
    {
        vector<int> positive;
        vector<int> negative;

        // Separate positive and negative numbers
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= 0)
            {
                positive.push_back(arr[i]);
            }
            else
            {
                negative.push_back(arr[i]);
            }
        }

        int i = 0;
        int j = 0;
        int k = 0;

        // Interleave positive and negative numbers
        while (j < positive.size() && k < negative.size())
        {
            arr[i++] = positive[j++];
            arr[i++] = negative[k++];
        }

        // Fill the remaining positive numbers
        while (j < positive.size())
        {
            arr[i++] = positive[j++];
        }

        // Fill the remaining negative numbers
        while (k < negative.size())
        {
            arr[i++] = negative[k++];
        }
    }
};

int main()
{

    return 0;
}