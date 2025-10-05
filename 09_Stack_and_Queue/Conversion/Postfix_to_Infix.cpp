#include <iostream>
#include <stack>
using namespace std;

string postToInfix(string str)
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

            string toPush = "(" + first + str[i] + second + ")";
            st.push(toPush);
        }
    }
    return st.top();
}

/*
1. Read the expression from left to right.

2. If the character is an operand (like A, 1, etc.) →
Push it onto the stack.

3. If the character is an operator (like +, -, *, /, ^) →

    Pop the top two elements from the stack (say second and first).

    Form a new infix expression:
    ("(" + first + operator + second + ")")

    Push this new expression back onto the stack.

4. After processing all characters, the stack will contain one final string — your complete infix expression.
*/