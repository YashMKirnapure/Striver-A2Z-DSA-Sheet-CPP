#include <iostream>
using namespace std;

string removeOuterParentheses(string s) 
    {
        int n = s.size();
        int depth = 0;
        string res;

        for(char c : s)
        {
            if(c == '(')
            {
                if(depth > 0)
                    res = res + c;
                depth++;
            }
            else
            {
                depth--;
                if(depth > 0)
                    res = res + c;   
            }
        }
        return res;
    }