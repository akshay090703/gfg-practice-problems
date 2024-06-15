#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int maxProd = INT_MIN;
        int prefix = 1;
        int suffix = 1;

        for (int i = 0; i < n; i++)
        {
            if (prefix == 0 or prefix >= 1000000000 or prefix <= -1000000000)
                prefix = 1;
            if (suffix == 0 or suffix >= 1000000000 or suffix <= -1000000000)
                suffix = 1;

            prefix *= nums[i];
            suffix *= nums[n - i - 1];

            maxProd = max({prefix, suffix, maxProd});
        }

        return maxProd;
    }
};

// Using Kadane's Algo
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         int maxProd = nums[0];

//         int prod1 = nums[0], prod2 = nums[0];

//         for(int i = 1; i<n; i++) {
//             if (prod1 == 0 or prod1 >= 1000000000 or prod1 <= -1000000000)
//                 prod1 = 1;
//             if (prod2 == 0 or prod2 >= 1000000000 or prod2 <= -1000000000)
//                 prod2 = 1;

//             int temp = max({nums[i], prod1 * nums[i], prod2 * nums[i]});
//             prod1 = min({nums[i], prod1 * nums[i], prod2 * nums[i]});
//             prod2 = temp;

//             maxProd = max(maxProd, prod2);
//         }

//         return maxProd;
//     }
// };

int main() {}