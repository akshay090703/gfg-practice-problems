//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[], int low, int mid, int high)
    {
        int left = low;
        int right = mid + 1;
        vector<long long> temp;

        long long int count = 0;

        while (left <= mid and right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                count += (mid - left + 1);
                right++;
            }
        }

        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        int j = 0;
        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[j];
            j++;
        }

        return count;
    }

    long long int mergeSort(long long arr[], int low, int high)
    {
        long long int inversions = 0;

        if (low >= high)
            return inversions;

        int mid = low + ((high - low) / 2);

        inversions += mergeSort(arr, low, mid);
        inversions += mergeSort(arr, mid + 1, high);
        inversions += merge(arr, low, mid, high);

        return inversions;
    }

    long long int inversionCount(int N, long long arr[])
    {
        return mergeSort(arr, 0, N - 1);
    }
};

//{ Driver Code Starts.

int main()
{

    long long T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(N, A) << endl;
    }

    return 0;
}

// } Driver Code Ends