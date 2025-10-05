#include <iostream>
#include <stack>
using namespace std;

string preToPost(string str)
{
    int n = str.size();
    stack<string> st;

    for (int i = n - 1; i >= 0; i--)
    {
        if (isalnum(str[i]))
            st.push(string(1, str[i]));
        else
        {
            string first = st.top();
            st.pop();

            string second = st.top();
            st.pop();

            string toPush = first + second + str[i];
            st.push(toPush);
        }
    }
    return st.top();
}

/*
1. Read the prefix expression from right to left.

2. If the character is an operand (like A, B, 1, etc.):
    → Push it onto the stack.

3. If the character is an operator (like +, -, *, /, ^):

    Pop the top two elements from the stack (say first and second).

    Form a new string:
    first + second + operator
    
    Push this combined string back onto the stack.

4. After processing all characters, the stack’s top element is your final postfix expression.
*/