//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        string result = "";
        unordered_map<char, int> occ;
        queue<char> q;

        for (int i = 0; i < A.length(); i++)
        {
            if (occ.find(A[i]) == occ.end())
            {
                if (!q.empty())
                {
                    result.push_back(q.front());
                }
                else
                {
                    result.push_back(A[i]);
                }

                q.push(A[i]);

                occ[A[i]]++;
            }
            else
            {
                occ[A[i]]++;

                while (q.size() > 0 and occ[q.front()] > 1)
                {
                    q.pop();
                }

                if (q.size() == 0)
                {
                    result.push_back('#');
                }
                else
                {
                    result.push_back(q.front());
                }
            }
        }

        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends