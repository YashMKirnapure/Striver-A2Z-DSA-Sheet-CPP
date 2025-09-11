#include <iostream>
using namespace std;

int myAtoi(string str)
{
    int n = str.size();
    long long res = 0;
    int sign = 1;
    int i = 0;

    while (i < n && str[i] == ' ')
        i++;

    if (i < n && (str[i] == '-' || str[i] == '+'))
    {
        if (str[i] == '-')
            sign = -1;
        else
            sign = 1;
        i++;
    }

    while (isdigit(str[i]))
    {
        res = res * 10 + (str[i] - '0');
        if (res * sign >= INT_MAX)
            return INT_MAX;
        if (res * sign <= INT_MIN)
            return INT_MIN;
        i++;
    }
    return res * sign;
}

/*
1. Skip leading whitespaces.
2. Check for sign (+ or -).
3. Convert characters to digits while they are numeric.
4. Handle overflow/underflow:
    If res > INT_MAX / 10 OR
    res == INT_MAX / 10 and next digit exceeds limit.
5. Return res * sign.
*/