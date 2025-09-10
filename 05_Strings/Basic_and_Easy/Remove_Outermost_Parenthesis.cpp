#include <iostream>
using namespace std;

string removeOuterParentheses(string s)
{
    int n = s.size();
    int depth = 0;
    string res;

    for (char c : s)
    {
        if (c == '(')
        {
            if (depth > 0)
                res = res + c;
            depth++;
        }
        else
        {
            depth--;
            if (depth > 0)
                res = res + c;
        }
    }
    return res;
}

/*
1. Track depth of parentheses

    We keep a depth counter.

    Each time we see "(", we increase depth.

    Each time we see ")", we decrease depth.

2. Decide when to add characters

    If we see "(" and we are already inside another "(" (i.e., depth > 0), then this "(" is not the outermost one → so we add it.

    If we see ")" and after reducing depth we are still inside (i.e., depth > 0), then this ")" is not the outermost one → so we add it.

3. Effectively

    The very first "(" of a group (when depth = 0 before adding) is skipped.

    The very last ")" of a group (when depth = 1 before decreasing) is skipped.

    Everything else (the real insides) gets added to res.

4.Return the final string → which is the input string without the “outer shells” of each primitive parentheses group.
*/