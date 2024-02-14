#include <iostream>
using namespace std;

class Solution
{
public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n)
    {
        if (n <= 0)
        {
            return false;
        }

        // The power of 2 has only one bit set. So, if n & (n-1) is 0, it's a power of 2.
        return (n & (n - 1)) == 0;
    }
};

int main()
{

    return 0;
}