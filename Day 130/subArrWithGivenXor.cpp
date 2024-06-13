#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &A, int B)
    {
        unordered_map<int, int> mp;
        int currXor = 0;
        int count = 0;
        for (int i = 0; i < A.size(); i++)
        {
            currXor ^= A[i];

            if (currXor == B)
                count++;

            if (mp.find(currXor ^ B) != mp.end())
            {
                count += mp[currXor ^ B];
            }

            mp[currXor]++;
        }

        return count;
    }
};

int main() {}