//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr1,arr2 : the arrays
    //  n, m: size of arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> result;
        unordered_map<int, bool> isVisited;

        int i = 0, j = 0;
        while (i < n or j < m)
        {
            if (i < n)
            {
                while (i < n and isVisited.find(arr1[i]) != isVisited.end())
                {
                    i++;
                }
            }

            if (j < m)
            {
                while (j < m and isVisited.find(arr2[j]) != isVisited.end())
                {
                    j++;
                }
            }

            int firstVal = INT_MAX, secondVal = INT_MAX;

            if (i < n)
                firstVal = arr1[i];

            if (j < m)
                secondVal = arr2[j];

            if (firstVal != INT_MAX or secondVal != INT_MAX)
            {
                if (firstVal > secondVal)
                {
                    result.push_back(secondVal);
                    isVisited[secondVal] = true;

                    j++;
                }
                else
                {
                    result.push_back(firstVal);
                    isVisited[firstVal] = true;

                    i++;
                }
            }
        }

        return result;
    }
};

//{ Driver Code Starts.

int main()
{

    int T;
    cin >> T;

    while (T--)
    {

        int N, M;
        cin >> N >> M;

        int arr1[N];
        int arr2[M];

        for (int i = 0; i < N; i++)
        {
            cin >> arr1[i];
        }

        for (int i = 0; i < M; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        vector<int> ans = ob.findUnion(arr1, arr2, N, M);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends