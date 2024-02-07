#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int getPairsCount(int arr[], int n, int k)
    {
        unordered_map<int, int> frequency;

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int diff = k - arr[i];
            if (frequency.find(diff) != frequency.end())
            {
                count += frequency[diff];
            }

            frequency[arr[i]]++;
        }

        return count;
    }
};

int main()
{

    return 0;
}