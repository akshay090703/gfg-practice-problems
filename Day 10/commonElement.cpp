#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        vector<int> result;
        int i = 0, j = 0, k = 0;

        while (i < n1 && j < n2 && k < n3)
        {
            if (A[i] == B[j] && B[j] == C[k])
            {
                if (find(result.begin(), result.end(), A[i]) == result.end())
                {
                    result.push_back(A[i]);
                }

                i++;
                j++;
                k++;
            }
            else if (A[i] < B[j])
            {
                i++;
            }
            else if (B[j] < C[k])
            {
                j++;
            }
            else
            {
                k++;
            }
        }

        if (result.size() == 0)
        {
            result.push_back(-1);
        }

        return result;
    }
};

int main()
{

    return 0;
}