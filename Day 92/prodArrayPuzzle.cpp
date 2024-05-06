//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
    {
        long long int prod = 1;
        bool isZero = false;
        bool multipleZeros = false;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                if (isZero)
                    multipleZeros = true;

                isZero = true;
            }
            else
            {
                prod *= nums[i];
            }
        }

        vector<long long int> prodArr(n, 0);
        if (!isZero)
        {
            for (int i = 0; i < n; i++)
            {
                prodArr[i] = prod / nums[i];
            }
        }
        else
        {
            if (multipleZeros)
                return prodArr;

            for (int i = 0; i < n; i++)
            {
                if (nums[i] == 0)
                {
                    prodArr[i] = prod;
                }
                else
                {
                    prodArr[i] = 0;
                }
            }
        }

        return prodArr;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; // number of test cases
    cin >> t;
    while (t--)
    {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr, n); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends