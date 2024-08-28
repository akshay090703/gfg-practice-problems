//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int> &arr)
    {
        int n = arr.size();

        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            freq[arr[i]]++;
        }

        sort(arr.begin(), arr.end(), [&freq](const int &a, const int &b)
             {
            if(freq[a] == freq[b]) {
                return a < b;
            }
            
            return freq[a] > freq[b]; });

        return arr;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num)
        {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends