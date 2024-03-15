//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int *greaterElement(int arr[], int n);

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int *b;
        b = greaterElement(arr, n);
        for (int i = 0; i < n; i++)
        {
            if (b[i] == -10000000)
                cout << "_ ";
            else
                cout << b[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

int binarySearch(vector<int> &a, int target)
{
    int start = 0, end = a.size() - 1;
    int mid = 0;

    while (start <= end)
    {
        mid = start + ((end - start) / 2);
        if (a[mid] == target)
        {
            break;
        }
        else if (a[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    while (mid + 1 < a.size() and a[mid] == a[mid + 1])
    {
        mid++;
    }

    if (mid + 1 >= a.size())
    {
        return -10000000;
    }

    return a[mid + 1];
}

int *greaterElement(int arr[], int n)
{
    vector<int> temp(n);
    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[i];
    }
    sort(temp.begin(), temp.end());

    for (int i = 0; i < n; i++)
    {
        arr[i] = binarySearch(temp, arr[i]);
    }

    return arr;
}
