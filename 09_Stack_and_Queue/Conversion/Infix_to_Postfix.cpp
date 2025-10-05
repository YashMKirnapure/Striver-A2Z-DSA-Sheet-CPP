#include <iostream>
#include <stack>
using namespace std;

int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '^')
        return 3;
    else
        return -1;
}

string infixToPostfix(string s)
{
    string res;
    stack<char> st;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (isalnum(s[i]))
            res = res + s[i];
        else if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                char c = st.top();
                st.pop();
                res = res + c;
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && precedence(s[i]) <= precedence(st.top()))
            {
                char c = st.top();
                st.pop();
                res = res + c;
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        char c = st.top();
        st.pop();
        res = res + c;
    }
    return res;
}

/*
1. Read the expression from left to right.

2. If it’s an operand (like A, 1, etc.), add it directly to the result.

3. If it’s an opening bracket (, push it onto the stack.

4. If it’s a closing bracket ), pop operators from the stack and add them to the result until you find a matching (. Then discard that (.

5. If it’s an operator (+, -, *, /, ^):
    Pop operators from the stack with higher or equal precedence and add them to the result.
    Then push the current operator onto the stack.

6. After reading the entire expression, pop any remaining operators from the stack and add them to the result.
*/