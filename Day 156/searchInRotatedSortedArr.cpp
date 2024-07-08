//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findPartition(vector<int> &A, int start, int end, int n)
    {
        int flag = A[0];

        while (start <= end)
        {
            int mid = start + ((end - start) / 2);

            if ((mid == 0 and A[mid] > A[mid + 1]) or (mid == n - 1 and A[mid] < A[mid - 1]))
            {
                return mid;
            }

            if (A[mid] < flag and A[mid - 1] > A[mid])
                return mid - 1;
            if (A[mid] > flag and A[mid] > A[mid + 1])
                return mid;

            if (A[mid] > flag)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return -1;
    }

    int search(vector<int> &arr, int key)
    {
        int l = 0, h = arr.size() - 1;

        int partition = findPartition(arr, l, h, h + 1);

        if (partition == -1)
        {
            partition = h;
        }

        if (arr[0] == key)
            return 0;

        if (arr[0] < key)
        {
            h = partition;
        }
        else
        {
            l = partition + 1;
        }

        while (l <= h)
        {
            int mid = l + ((h - l) / 2);

            if (arr[mid] < key)
            {
                l = mid + 1;
            }
            else if (arr[mid] > key)
            {
                h = mid - 1;
            }
            else
            {
                return mid;
            }
        }

        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends