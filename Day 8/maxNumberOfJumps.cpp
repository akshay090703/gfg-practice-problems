#include <iostream>
using namespace std;

class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        if (n <= 1)
        {
            return 0;
        }

        if (arr[0] == 0)
        {
            return -1;
        }

        int jumps = 1;
        int steps = arr[0];
        int maxReach = arr[0];
        for (int i = 1; i < n; i++)
        {
            // if we have reached end, then return jumps
            if (i == n - 1)
            {
                return jumps;
            }

            // updating maxReach everytime
            maxReach = max(maxReach, i + arr[i]);

            // decreasing steps after every iteration
            steps--;

            if (steps == 0)
            {
                // now we would have to make a jump
                jumps++;

                // if i is more than maxReach, then it is impossible to reach end
                if (i >= maxReach)
                {
                    return -1;
                }

                // the number of steps that can be taken from now
                steps = maxReach - i;
            }
        }

        return -1;
    }
};

int main()
{

    return 0;
}