//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int totalFruits(int N, vector<int> &fruits)
    {
        int start = 0, end = 0;
        int max_trees = 0;

        unordered_map<int, int> occ;
        while (start < N and end < N)
        {
            occ[fruits[end]]++;
            end++;

            while (occ.size() > 2)
            {
                occ[fruits[start]]--;

                if (occ[fruits[start]] == 0)
                {
                    occ.erase(fruits[start]);
                }

                start++;
            }

            max_trees = max(max_trees, end - start);
        }

        return max_trees;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++)
            cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends