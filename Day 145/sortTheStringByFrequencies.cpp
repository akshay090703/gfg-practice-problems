#include <bits/stdc++.h>
using namespace std;

// My approach
// Time Complexity-> O(nlogn)
// Space Complexity -> O(n)
// struct customCom
// {
//     bool operator()(const pair<char, int> &lhs, const pair<char, int> &rhs)
//     {
//         if (lhs.second == rhs.second)
//         {
//             return lhs.first < rhs.first;
//         }

//         return lhs.second > rhs.second;
//     }
// };

// class Solution
// {
// public:
//     string frequencySort(string s)
//     {
//         int n = s.length();

//         unordered_map<char, int> mp;
//         for (int i = 0; i < n; i++)
//         {
//             mp[s[i]]++;
//         }

//         vector<pair<char, int>> freqVector(mp.begin(), mp.end());

//         sort(freqVector.begin(), freqVector.end(), customCom());

//         string result = "";
//         for (auto pair : freqVector)
//         {
//             result.append(pair.second, pair.first);
//         }

//         return result;
//     }
// };

// Optimized Approach using Bucket Sort Approach
class Solution
{
public:
    string frequencySort(string s)
    {
        int n = s.length();
        unordered_map<char, int> mp;
        int maxFreq = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            mp[s[i]]++;
            maxFreq = max(maxFreq, mp[s[i]]);
        }

        // Creating Buckets for frequency sorting
        vector<vector<char>> freqArr(maxFreq + 1);
        for (auto pair : mp)
        {
            freqArr[pair.second].push_back(pair.first);
        }

        string result = "";
        for (int i = maxFreq; i > 0; i--)
        {
            for (char ch : freqArr[i])
            {
                result.append(i, ch);
            }
        }

        return result;
    }
};

int main()
{

    return 0;
}