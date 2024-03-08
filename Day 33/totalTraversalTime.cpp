//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends
class Solution
{
public:
    int totalTime(int n, vector<int> &arr, vector<int> &penalty)
    {
        unordered_map<int, bool> isOccurred;
        int totalTime = 0;

        for (int i = 0; i < n; i++)
        {
            if (!isOccurred[arr[i]])
            {
                isOccurred[arr[i]] = true;
                if (i != 0)
                {
                    totalTime++;
                }
            }
            else
            {
                totalTime += penalty[arr[i] - 1];
            }
        }

        return totalTime;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> penalty(n);
        Array::input(penalty, n);

        Solution obj;
        int res = obj.totalTime(n, arr, penalty);

        cout << res << endl;
    }
}

// } Driver Code Ends