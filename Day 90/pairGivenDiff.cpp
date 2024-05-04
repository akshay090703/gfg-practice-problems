//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, n;
        cin >> l >> n;
        int arr[l];
        for (int i = 0; i < l; i++)
            cin >> arr[i];
        if (findPair(arr, l, n))
            cout << 1 << endl;
        else
            cout << "-1" << endl;
    }

    return 0;
}
// } Driver Code Ends

bool binarySearch(int arr[], int n, int pos, int needed_num)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (arr[mid] == needed_num)
        {
            if (pos == mid)
            {
                if (mid > 0 and mid < n - 1 and (arr[mid] == arr[mid - 1] or arr[mid] == arr[mid + 1]))
                {
                    return true;
                }

                if ((mid == 0 and arr[mid] == arr[mid + 1]) or (mid == n - 1 and arr[mid] == arr[mid - 1]))
                {
                    return true;
                }

                return false;
            }

            return true;
        }
        else if (arr[mid] < needed_num)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return false;
}

bool findPair(int arr[], int size, int n)
{
    sort(arr, arr + size);

    for (int i = 0; i < size; i++)
    {
        if (arr[i] - n >= arr[0])
        {
            if (binarySearch(arr, size, i, arr[i] - n))
            {
                return true;
            }
        }
    }

    return false;
}