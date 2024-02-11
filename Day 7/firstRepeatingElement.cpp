#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n)
    {
        unordered_map<int, int> occurances;
        int result = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (occurances.find(arr[i]) != occurances.end())
            {
                // found a repeating and simply updating result with the minimum repeating index till now
                result = min(result, occurances[arr[i]]);
            }
            else
            {
                // simply storing the 1-based indexing in the map
                occurances[arr[i]] = i + 1;
            }
        }

        return (result != INT_MAX) ? result : -1;
    }
};

int main()
{

    return 0;
}