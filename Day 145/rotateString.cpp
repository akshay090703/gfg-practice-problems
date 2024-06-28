#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        int n = s.length();
        int m = goal.length();

        if (n != m)
            return false;

        goal += goal;
        if (goal.find(s) != string::npos)
            return true;

        return false;
    }
};

int main()
{

    return 0;
}