#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    void segregateElements(int arr[], int n)
    {
        vector<int> negativeNum;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
            {
                negativeNum.push_back(arr[i]);
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= 0)
            {
                arr[count++] = arr[i];
            }
        }

        for (int i = 0; i < negativeNum.size(); i++)
        {
            arr[count++] = negativeNum[i];
        }
    }
};

int main()
{

    return 0;
}