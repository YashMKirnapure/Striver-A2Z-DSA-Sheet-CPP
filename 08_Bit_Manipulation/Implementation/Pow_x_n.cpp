#include <iostream>
using namespace std;

double myPow(double x, int n)
{
    double ans = 1.0;
    long long tempn = n;

    if (tempn < 0)
    {
        x = 1 / x;
        tempn = -tempn;
    }

    while (tempn > 0)
    {
        if (tempn & 1)
        {
            ans = ans * x;
            tempn = tempn - 1;
        }
        else
        {
            x = x * x;
            tempn = tempn >> 1;
        }
    }
    return ans;
}

/*
1. You want to compute x^n
. If n is negative, just flip it: compute 1/x^−n

2. Now, instead of multiplying x n times (slow), break it down with binary powers:
    If the current exponent (tempn) is odd → multiply ans by x once, and reduce tempn by 1.
    If it’s even → square x and halve tempn.

3. Keep going until exponent becomes 0.

4. ans holds the final answer.

Example Walkthrough: myPow(2, 10)
x = 2, n = 10, ans = 1
10 is even → square x → x = 4, tempn = 5
5 is odd → ans = ans * x = 4, tempn = 4
4 is even → x = 16, tempn = 2
2 is even → x = 256, tempn = 1
1 is odd → ans = ans * x = 4 * 256 = 1024, tempn = 0
Done → result = 1024.
*/