//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int diff = INT_MAX;
        int sum = 0;
        
        for(int i = 0; i<n; i++) {
            int left = i + 1, right = n - 1;
            while(left < right) {
                int curr_sum = arr[i] + arr[left] + arr[right];
                
                if(abs(diff) == abs(curr_sum - target)) {
                    if(curr_sum > target) {
                        sum = curr_sum;
                        diff = curr_sum - target;
                    }
                } else if(abs(diff) > abs(curr_sum - target)) {
                    sum = curr_sum;
                    diff = curr_sum - target;
                }
                
                if(curr_sum < target) {
                    left++;
                } else if(curr_sum > target) {
                    right--;  
                } else {
                    left++;
                    right--;
                }
            }
        }
        
        return sum;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends