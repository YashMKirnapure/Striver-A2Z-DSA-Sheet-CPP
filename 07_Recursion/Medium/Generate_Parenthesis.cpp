#include <iostream>
#include <vector>
using namespace std;

void func(vector<string> &ans, string res, int open, int close, int n)
{
    if (res.size() == 2 * n)
    {
        ans.push_back(res);
        return;
    }
    if (open < n)
        func(ans, res + "(", open + 1, close, n);
    if (close < open)
        func(ans, res + ")", open, close + 1, n);
}

vector<string> generateParenthesis(int n)
{
    string res = "";
    vector<string> ans;
    func(ans, res, 0, 0, n);
    return ans;
}

/*
1. We have two types of brackets: opening ( and closing ).

2. A valid arrangement means:
    You can’t close a bracket before opening one.
    You can’t use more than n opening or closing brackets.

3. Start with an empty string. At each step, we have two choices:
    If we haven’t used up all our opening brackets, we can add an (.
    If we’ve already placed some (, we are allowed to add a ) (but only if it won’t exceed the number of openings).

4. Keep adding brackets step by step until the string length becomes 2 * n (because each pair contributes 2 characters).
    If the string is valid by this point, keep it in the results.

5. Do this for all possible paths. The rules automatically prevent bad strings like ())( or )))((.
*/