#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> leaders(int a[], int n)
    {
        vector<int> ans;
        ans.push_back(a[n - 1]);
        int maxEl = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            maxEl = max(a[i], maxEl);
            if (a[i] >= maxEl)
            {
                ans.push_back(a[i]);
            }
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{

    return 0;
}