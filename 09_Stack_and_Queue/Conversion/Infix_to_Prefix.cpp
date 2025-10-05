#include <iostream>
#include <stack>
using namespace std;

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return 0;
}

string ModifiedInfixToPostfix(string &str)
{
    int n = str.size();
    stack<char> st;
    string ans;

    for (int i = 0; i < n; i++)
    {
        if (isalnum(str[i]))
            ans = ans + str[i];
        else
        {
            if (str[i] == '(')
                st.push(str[i]);
            else if (str[i] == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    ans = ans + st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.empty() && (str[i] == '^' && precedence(str[i]) <= precedence(st.top()) || str[i] != '^' && precedence(str[i]) < precedence(st.top())))
                {
                    ans = ans + st.top();
                    st.pop();
                }
                st.push(str[i]);
            }
        }
    }
    while (!st.empty())
    {
        ans = ans + st.top();
        st.pop();
    }
    return ans;
}

string infixToPrefix(string &str)
{
    int n = str.size();

    // Step 1
    reverse(str.begin(), str.end());

    // Change ( to ) and vice versa
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
            str[i] = ')';
        else if (str[i] == ')')
            str[i] = '(';
    }

    // Step 2
    str = ModifiedInfixToPostfix(str);

    // Step 3
    reverse(str.begin(), str.end());

    return str;
}

/*
1. Reverse the infix expression.
Example: (A-B/C)*(A/K-L) → )L-K/A(* )C/B-A(

2. Swap every bracket.
Change every ( to ) and every ) to (.
Now it becomes: (L-K/A)*((A-B/C)

3. Convert the modified expression to postfix using a standard infix-to-postfix algorithm (handled by ModifiedInfixToPostfix()),
taking special care of right-associative operators like ^.

4. Reverse the postfix result to get the final prefix expression.
*/