#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &a, int n, int x)
{
    int start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (a[mid] > x)
        {
            end = mid - 1;
        }
        else if (a[mid] < x)
        {
            start = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return end;
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
    if (a[0] > x)
        return {-1, a[0]};
    if (a[n - 1] < x)
        return {a[n - 1], -1};

    int idx = binarySearch(a, n, x);

    if (a[idx] == x)
    {
        return {a[idx], a[idx]};
    }
    else if (a[idx] > x)
    {
        return {a[idx - 1], a[idx]};
    }

    return {a[idx], a[idx + 1]};
}

int main()
{

    return 0;
}