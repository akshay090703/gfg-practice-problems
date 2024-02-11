#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

vector<vector<long long>> generatePascalsTriangle(int numRows)
{
    vector<vector<long long>> result;

    for (int i = 0; i < numRows; ++i)
    {
        vector<long long> row(i + 1, 1);

        for (int j = 1; j < i; ++j)
        {
            row[j] = (result[i - 1][j - 1] + result[i - 1][j]) % MOD;
        }

        result.push_back(row);
    }

    return result[numRows - 1];
}

int main()
{

    return 0;
}