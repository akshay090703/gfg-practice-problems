//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> temp; // storing original index
        for (int i = 0; i < n; i++)
        {
            temp.push_back({nums[i], i});
        }

        sort(temp.begin(), temp.end());
        int swaps = 0;

        vector<bool> isVisited(n, false);
        for (int i = 0; i < n; i++)
        {
            // means that the element is at correct position
            if (isVisited[i] or temp[i].second == i)
            {
                continue;
            }

            int j = i;
            int cycles = 0;
            while (!isVisited[j])
            {
                isVisited[j] = true;
                j = temp[j].second;
                cycles++;
            }

            if (cycles > 0)
            {
                swaps += cycles - 1;
            }
        }

        return swaps;
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
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        int ans = obj.minSwaps(nums);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends