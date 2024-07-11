#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        int n = asteroids.size();
        vector<int> result;
        stack<int> st;

        for (int ast : asteroids)
        {
            bool destroyed = false;
            while (!st.empty() and ast < 0 and st.top() > 0)
            {
                if (-ast > st.top())
                {
                    st.pop();
                    continue;
                }
                else if (-ast == st.top())
                {
                    st.pop();
                }

                destroyed = true;
                break;
            }

            if (!destroyed)
            {
                st.push(ast);
            }
        }

        while (!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main()
{

    return 0;
}