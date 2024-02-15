#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string reverseWord(string str)
    {
        reverse(str.begin(), str.end());
        return str;
    }
};

int main()
{

    return 0;
}