#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
    {
        n = abs(n);
        x = 1 / x;
    }
    if (n % 2 == 0)
        return myPow(x * x, n / 2);
    else
        return x * myPow(x, n - 1);
}

/*
Step 1: Handle the simple cases

If 𝑛=0: anything to the power of zero is 1. Done.
If n<0: instead of calculating x^n, flip it to (1/𝑥)^−𝑛
.Example:
2^-3 = (1/2)^3 = 1/8.

Step 2: Use the “divide and conquer” trick
Instead of multiplying x repeatedly, notice:

If n is even:
x^n=(x2)^n/2

Example: 
2^8=(2^2)^4=4^4
We cut the problem size in half each time.

If n is odd:
x^n=x*x^n−1

Example: 
2^5 = 2×2^4

After peeling off one x, the rest becomes an even power, which we know how to handle.

Step 3: Repeat until done
Keep applying step 2 recursively (or iteratively) until n reduces to zero.
*/