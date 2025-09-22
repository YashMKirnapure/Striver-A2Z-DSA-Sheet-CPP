#include <iostream>
#include <algorithm>
using namespace std;

int func(long long res, string str, int sign, int i, int n)
{
    if (res * sign <= INT_MIN)
        return INT_MIN;
    if (res * sign >= INT_MAX)
        return INT_MAX;
    if (isdigit(str[i]))
        return func(res * 10 + (str[i] - '0'), str, sign, i + 1, n);
    return res * sign;
}

int myAtoi(string str)
{
    long long res = 0;
    int i = 0;
    int sign = 1;
    int n = str.size();

    while (str[i] == ' ' && i < n)
        i++;

    if (i < n && (str[i] == '-' || str[i] == '+'))
    {
        if (str[i] == '-')
            sign = -1;
        else
            sign = 1;
        i++;
    }

    return func(res, str, sign, i, n);
}

/*
Step 1: Prepare for conversion
    Start with result res = 0, sign = +1 by default.
    Skip all the leading spaces in the string.
    Check for a sign symbol ('-' or '+').
        If '-', flip sign to -1.
        If '+', keep sign as +1.

Step 2: Recursively build the number
    Start from the first digit character.
    At each step:
        If the current character is a digit:
            Update res = res * 10 + (digit value) (shift old digits left, add new one).
            Move to the next character → recursive call.
If the character is not a digit → stop recursion, return the result so far.

Step 3: Handle overflow
    Before processing each digit, check:
        If res * sign goes below INT_MIN, return INT_MIN.
        If it goes above INT_MAX, return INT_MAX.
This keeps the result clamped within 32-bit signed integer range.

*/