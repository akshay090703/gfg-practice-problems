#include <iostream>
#include <vector>
using namespace std;

void copyAllElements(vector<long long> &finalAns, long long arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        finalAns.insert(finalAns.begin(), arr[i]);
    }
}

void solve(vector<long long> &ans, long long arr[], int n)
{
    if (n == 1)
    {
        return;
    }

    int i = 0;
    long long temp[n - 1];
    while (i < n - 1)
    {
        temp[i] = arr[i] + arr[i + 1];
        i++;
    }

    copyAllElements(ans, temp, n - 1);

    solve(ans, temp, n - 1);
}

vector<long long> getTriangle(int arr[], int n)
{
    vector<long long> finalAns;

    long long startingArr[n];
    for (int i = 0; i < n; i++)
    {
        startingArr[i] = arr[i];
    }
    copyAllElements(finalAns, startingArr, n);

    solve(finalAns, startingArr, n);

    return finalAns;
}

int main()
{

    return 0;
}