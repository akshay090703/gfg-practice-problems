//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int shortestDistance(vector<string> &s, string word1, string word2)
    {
        int n = s.size();

        if (word1 == word2)
            return 0;

        int minDistance = INT_MAX;
        int firstWord = -1, secondWord = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == word1)
            {
                firstWord = i;

                if (secondWord != -1)
                {
                    minDistance = min(minDistance, abs(firstWord - secondWord));
                }
            }
            else if (s[i] == word2)
            {
                secondWord = i;

                if (firstWord != -1)
                {
                    minDistance = min(minDistance, abs(firstWord - secondWord));
                }
            }
        }

        return minDistance;
    }
};

//{ Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<string> s(n);
        for (int i = 0; i < n; i++)
            cin >> s[i];

        string word1, word2;

        cin >> word1 >> word2;

        Solution ob;

        cout << ob.shortestDistance(s, word1, word2) << "\n";
    }

    return 0;
}
// } Driver Code Ends