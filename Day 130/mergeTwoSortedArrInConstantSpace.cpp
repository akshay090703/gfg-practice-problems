#include <bits/stdc++.h>
using namespace std;

// Shell Sort

// Without shell sort
// class Solution
// {
// public:
//     void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
//     {
//         int left = m - 1;
//         int right = 0;

//         while (left >= 0 and right < n)
//         {
//             if (nums1[left] > nums2[right])
//             {
//                 swap(nums1[left], nums2[right]);
//                 left--;
//                 right++;
//             }
//             else
//             {
//                 break;
//             }
//         }

//         sort(nums1.begin(), nums1.begin() + m);
//         sort(nums2.begin(), nums2.end());

//         int i = m, j = 0;
//         while (i < m + n and j < n)
//         {
//             nums1[i] = nums2[j];
//             i++;
//             j++;
//         }
//     }
// };
// Time Complexity: O(min(n, m)) + O(n*logn) + O(m*logm), where n and m are the sizes of the given arrays.
//  Reason: O(min(n, m)) is for swapping the array elements. And O(n*logn) and O(m*logm) are for sorting the two arrays.
//  Space Complexity: O(1) as we are not using any extra space.

int main() {}
