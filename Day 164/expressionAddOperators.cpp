//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void solve(vector<string> &result, string &S, int target, string curr, int idx, long long prev, long long res)
    {
        if (idx == S.length())
        {
            if (res == target)
                result.push_back(curr);

            return;
        }

        string str = "";
        long long currRes = 0;
        for (int i = idx; i < S.length(); i++)
        {
            if (i > idx and S[idx] == '0')
                break;

            str += S[i];
            currRes = (currRes * 10) + (S[i] - '0');

            if (idx == 0)
            {
                solve(result, S, target, str, i + 1, currRes, currRes);
            }
            else
            {
                solve(result, S, target, curr + '+' + str, i + 1, currRes, res + currRes);
                solve(result, S, target, curr + '-' + str, i + 1, -currRes, res - currRes);
                solve(result, S, target, curr + '*' + str, i + 1, prev * currRes, (res - prev) + (prev * currRes));
            }
        }
    }

    vector<string> addOperators(string &S, int target)
    {
        vector<string> result;
        solve(result, S, target, "", 0, 0, 0);

        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans)
            cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends