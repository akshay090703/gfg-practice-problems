#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> recamanSequence(int n)
    {
        unordered_map<int, bool> isIncluded;
        vector<int> sequence;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                sequence.push_back(0);
            }
            else
            {
                int calculation = sequence[i - 1] - i;
                if (isIncluded[calculation] or calculation <= 0)
                {
                    calculation = sequence[i - 1] + i;
                }

                isIncluded[calculation] = true;
                sequence.push_back(calculation);
            }
        }

        return sequence;
    }
};

int main()
{

    return 0;
}