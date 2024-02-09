#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> duplicates(long long arr[], int n)
    {
        vector<int> ans;

        // number : occurance
        map<long long, int> occurances; // to maintain order of ans array
        for (int i = 0; i < n; i++)
        {
            occurances[arr[i]]++;
        }

        for (auto it = occurances.begin(); it != occurances.end(); ++it)
        {
            if (it->second > 1)
            {
                ans.push_back(it->first);
            }
        }

        if (ans.size() == 0)
        {
            ans.push_back(-1);
        }

        return ans;
    }
};

int main()
{

    return 0;
}