#include <iostream>
using namespace std;

class Solution
{
public:
    // Moore's Voting Algorithm

    // function to find candidate for majority element
    int findCandidate(int a[], int size)
    {
        int maj_index = 0, count = 1;
        for (int i = 1; i < size; i++)
        {
            if (a[maj_index] == a[i])
            {
                count++;
            }
            else
            {
                count--;
            }

            if (count == 0)
            {
                maj_index = i;
                count = 1;
            }
        }

        return a[maj_index];
    }

    bool isDominant(int a[], int element, int size)
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (a[i] == element)
            {
                count++;
            }
        }

        if (count > (size / 2))
        {
            return true;
        }

        return false;
    }

    int majorityElement(int a[], int size)
    {
        int ans = -1;
        int candidate = findCandidate(a, size);

        if (isDominant(a, candidate, size))
        {
            return candidate;
        }

        return -1;
    }
};

int main()
{

    return 0;
}