#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k)
    {
        unordered_map<int, int> occurances;
        for (int i = 0; i < n; i++)
        {
            occurances[arr[i]]++;
        }

        int count = 0;

        for (auto i = occurances.begin(); i != occurances.end(); i++)
        {
            if (i->second > (n / k))
            {
                count++;
            }
        }

        return count;
    }
};

int main()
{

    return 0;
}