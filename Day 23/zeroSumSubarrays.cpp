//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    long long int sumOfNaturalNumbers(int nums)
    {
        return ((nums * (nums + 1)) / 2);
    }

    // Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n)
    {
        // sum : list of i's
        // we made an ordered map because we want the order as here we want to count subarrays
        map<int, list<int>> sumMap;
        long long int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            sumMap[sum].push_back(i);
        }

        long long int count = 0;
        for (auto i = sumMap.begin(); i != sumMap.end(); i++)
        {
            if (i->first == 0)
            {
                count += i->second.size(); // all 0 elements are itself a subarray
            }

            if (i->first != 0 and i->second.size() == 1)
            {
                continue; // if there is only one sum instance then just skip
            }

            // add all the possible subarray combinations that can add upto 0
            count += sumOfNaturalNumbers(i->second.size() - 1);
        }

        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n; // input size of array

        vector<long long int> arr(n, 0);

        for (int i = 0; i < n; i++)
            cin >> arr[i]; // input array elements
        Solution ob;
        cout << ob.findSubarray(arr, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends