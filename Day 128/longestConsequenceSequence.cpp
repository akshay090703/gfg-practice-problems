#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        unordered_set<int> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(nums[i]);
        }

        int count = 0;
        int max_count = 0;
        for (auto it = st.begin(); it != st.end(); it++)
        {
            int element = *it;

            if (st.find(element - 1) == st.end())
            {
                count++;
                element++;
                while (st.find(element) != st.end())
                {
                    count++;
                    element++;
                }
            }

            max_count = max(max_count, count);
            count = 0;
        }

        return max_count;
    }
};

int main()
{
}