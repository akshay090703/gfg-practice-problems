//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void solve(int a[], int n, vector<string> &mapping, string &curr, vector<string> &result, int i)
    {
        if (curr.length() == n)
        {
            result.push_back(curr);
            return;
        }

        string currDigit = mapping[a[i]];
        for (auto ch : currDigit)
        {
            curr.push_back(ch);
            solve(a, n, mapping, curr, result, i + 1);
            curr.pop_back();
        }
    }

    // Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string curr = "";
        vector<string> result;
        solve(a, N, mapping, curr, result, 0);

        return result;
    }
};

//{ Driver Code Starts.

int main()
{

    int T;

    cin >> T; // testcases

    while (T--)
    { // while testcases exist
        int N;

        cin >> N; // input size of array

        int a[N]; // declare the array

        for (int i = 0; i < N; i++)
        {
            cin >> a[i]; // input the elements of array that are keys to be pressed
        }

        Solution obj;

        vector<string> res = obj.possibleWords(a, N);
        for (string i : res)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends