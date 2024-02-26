//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void bubbleSort(int arr[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    // Function to find if there exists a triplet in the
    // array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        // bubble sort
        bubbleSort(A, n);

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int reqSum = X - A[i];
            int start = 0, end = n - 1;
            while (start < end)
            {
                if (start == i)
                {
                    start++;
                    continue;
                }

                if (end == i)
                {
                    end--;
                    continue;
                }

                if (A[start] + A[end] > reqSum)
                {
                    end--;
                }
                else if (A[start] + A[end] < reqSum)
                {
                    start++;
                }
                else if (A[start] + A[end] == reqSum)
                {
                    return true;
                }
            }
        }

        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, X;
        cin >> n >> X;
        int i, A[n];
        for (i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends