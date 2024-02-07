#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    // Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> st;
        for (int i = 0; i < x.length(); i++)
        {
            char node = x[i];
            if (node == ']' || node == '}' || node == ')')
            {
                if (!st.empty())
                {
                    char top = st.top();
                    if ((node == ']' && top == '[') || (node == '}' && top == '{') || (node == ')' && top == '('))
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false; // Stack is empty, but a closing parenthesis is encountered
                }
            }
            else
            {
                st.push(node);
            }
        }

        return st.empty(); // Expression is balanced if the stack is empty at the end
    }
};

int main()
{

    return 0;
}