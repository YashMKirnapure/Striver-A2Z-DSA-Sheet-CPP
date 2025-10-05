#include <iostream>
#include <stack>
using namespace std;

string postToPre(string str)
{
    int n = str.size();
    stack<string> st;

    for (int i = 0; i < n; i++)
    {
        if (isalnum(str[i]))
            st.push(string(1, str[i]));
        else
        {
            string second = st.top();
            st.pop();

            string first = st.top();
            st.pop();

            string toPush = str[i] + first + second;
            st.push(toPush);
        }
    }
    return st.top();
}

/*
1. Read the postfix expression from left to right.

2. If the character is an operand (like A, B, 1, etc.) →
    Push it onto the stack.

3. If the character is an operator (like +, -, *, /, ^) →
    Pop the top two elements from the stack (say second and first).
    Create a new string:
    operator + first + second
    Push this new string back onto the stack.

4. After processing the whole expression, the stack’s top will hold the final prefix expression.
*/