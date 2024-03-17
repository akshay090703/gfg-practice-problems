//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> topK(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> occurances;
        for (int i = 0; i < nums.size(); i++)
        {
            occurances[nums[i]]++;
        }

        // lambda function
        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b)
        {
            if (a.first == b.first)
            {
                return a.second < b.second;
            }

            return a.first < b.first;
        };

        // frequency : element
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> maxHeap(cmp);
        for (auto it = occurances.begin(); it != occurances.end(); ++it)
        {
            int value = it->first;
            int freq = it->second;

            maxHeap.push({freq, value});
        }

        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            if (!maxHeap.empty())
            {
                pair<int, int> topPair = maxHeap.top();
                maxHeap.pop();

                ans.push_back(topPair.second);
            }
            else
            {
                ans.push_back(0);
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums)
            cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends