#include <iostream>
using namespace std;

class Solution
{
public:
    // {max, {min, middle}}
    pair<int, pair<int, int>> minMax(int start, int mid, int end)
    {
        if (start >= mid && start >= end)
        {
            if (mid > end)
            {
                return {start, {end, mid}};
            }
            else
            {
                return {start, {mid, end}};
            }
        }
        else if (mid >= start and mid >= end)
        {
            if (start > end)
            {
                return {mid, {end, start}};
            }
            else
            {
                return {mid, {start, end}};
            }
        }
        else
        {
            if (start > mid)
            {
                return {end, {mid, start}};
            }
            else
            {
                return {end, {start, mid}};
            }
        }
    }

    void zigZag(int arr[], int n)
    {
        // code here
        int i = 0;
        int count = 0;
        while (i + 2 < n)
        {
            int start = i;
            int mid = i + 1;
            int end = i + 2;
            pair<int, pair<int, int>> temp = minMax(arr[start], arr[mid], arr[end]);

            int max = temp.first;
            int min = temp.second.first;
            int middle = temp.second.second;

            if (count % 2 == 0)
            {
                arr[mid] = max;
                arr[start] = min;
                arr[end] = middle;
            }
            else
            {
                arr[mid] = min;
                arr[end] = max;
                arr[start] = middle;
            }

            i++;
            count++;
        }
    }
};

int main()
{

    return 0;
}