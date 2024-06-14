#include <bits/stdc++.h>
using namespace std;

// Using Greedy Algorithm
class Solution
{
public:
    int minMovesToSeat(vector<int> &seats, vector<int> &students)
    {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int minMoves = 0;

        for (int i = 0; i < students.size(); i++)
        {
            minMoves += abs(seats[i] - students[i]);
        }

        return minMoves;
    }
};

int main() {}