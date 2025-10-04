#include <iostream>
#include <stack>
using namespace std;

bool isValid(string str)
{
    int n = str.size();

    if (n % 2 == 1)
        return false;
    if (str[0] == ')' || str[0] == '}' || str[0] == ']')
        return false;

    stack<char> st;

    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            st.push(str[i]);
        else if (str[i] == ')')
        {
            if (st.empty())
                return false;
            else
            {
                if (st.top() == '(')
                    st.pop();
                else
                    return false;
            }
        }
        else if (str[i] == '}')
        {
            if (st.empty())
                return false;
            else
            {
                if (st.top() == '{')
                    st.pop();
                else
                    return false;
            }
        }
        else if (str[i] == ']' && !st.empty())
        {
            if (st.empty())
                return false;
            else
            {
                if (st.top() == '[')
                    st.pop();
                else
                    return false;
            }
        }
    }
    return st.empty() ? true : false;
}

bool isValid(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
            st.push(c);
        else
        {
            if (st.empty())
                return false;
            if (c == ')' && st.top() != '(')
                return false;
            else if (c == ']' && st.top() != '[')
                return false;
            else if (c == '}' && st.top() != '{')
                return false;
            else
                st.pop();
        }
    }
    return st.empty();
}

/*
1. Use a stack to keep track of opening brackets: (, [, {.

2. Iterate through the string:
    If the current character is an opening bracket, push it onto the stack.
    If it’s a closing bracket:
        If the stack is empty → there’s no matching opening bracket → invalid.
        Otherwise, check if the top of the stack matches the corresponding opening bracket:
        ) → (
        ] → [
        } → {
    If it matches, pop the top element. Otherwise, return false.

3. After processing all characters, stack should be empty for the string to be valid.
*/