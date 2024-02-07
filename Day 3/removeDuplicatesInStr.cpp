#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string str)
    {
        string ans = "";
        unordered_map<char, bool> isVisited;
        for (int i = 0; i < str.length(); i++)
        {
            if (!isVisited[str[i]])
            {
                isVisited[str[i]] = true;
                ans.push_back(str[i]);
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}