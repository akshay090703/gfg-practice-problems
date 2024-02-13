#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        if (n == 0)
        {
            return {};
        }

        if (n == 1)
        {
            return {-1};
        }

        vector<long long> ans(n, -1);
        // pair of index and value
        stack<pair<long long, long long>> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[i] > st.top().second)
            {
                ans[st.top().first] = arr[i];
                st.pop();
            }

            st.push({i, arr[i]});
        }

        return ans;
    }
};

int main()
{

    return 0;
}