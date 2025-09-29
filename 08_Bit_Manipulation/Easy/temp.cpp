#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

string convert2Binary(int n)
{
    string res = "";
    while (n > 0)
    {
        if (n % 2 == 1)
            res += '1';
        else
            res += '0';
        n = n / 2;
    }

    reverse(res.begin(), res.end());
    return res;
}

int convert2Decimal(string str)
{
    int n = str.size();
    int res = 0;

    for(int i=n-1 ;i>=0 ;i--)
    {
        res = res + (str[i]-'0') * pow(2,n-1-i);
    }
    return res;
}

int main()
{
    cout<<convert2Binary(10);
    // cout<<convert2Decimal("1011");
}

/*
1. convert2Binary(int n)

We start with a decimal number n.

While n is greater than 0:
    If n is odd (n % 2 == 1), append '1' to the result string.
    If n is even, append '0'.
    Then divide n by 2 (integer division) to move to the next binary digit.

This process builds the binary number in reverse order (from least significant bit to most significant).

Finally, reverse the string so the binary representation is correct (MSB on the left, LSB on the right).

In short: it’s just repeatedly dividing by 2 and recording the remainders → that gives you the binary representation.

*/

/*
2. convert2Decimal(string str)

Here, we’re given a binary string (like "1011").

We traverse the string from right to left (because the rightmost bit is the least significant bit).

For each character:
    Convert it from '0' or '1' to an integer (str[i]-'0').
    Multiply it by 2^(position) where position is counted from the right.
    Add this value to the result.

After finishing the loop, we have the decimal equivalent.

In short: it’s just calculating the weighted sum of binary digits with powers of 2.

*/