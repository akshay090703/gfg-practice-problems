#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        int idx = -1;
        int firstEl = nums[0];

        while(start <= end) {
            int mid = start + ((end - start) / 2);

            if(firstEl <= nums[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
                idx = mid;
            }
        }

        if(idx != -1) return nums[idx];

        return nums[0];
    }
};

int main()
{
    
    return 0;
}