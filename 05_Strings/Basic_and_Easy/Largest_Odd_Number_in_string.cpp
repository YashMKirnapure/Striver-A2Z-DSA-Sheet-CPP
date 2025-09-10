#include <iostream>
using namespace std;

string largestOddNumber(string num)
{
    int n = num.size();

    for (int i = n - 1; i >= 0; i--)
    {
        if ((num[i] - '0') % 2 == 1)
            return num.substr(0, i + 1);
    }
    return "";
}

/*
1. Scan from the rightmost digit
    Start at the last digit of the string (n-1).
    Why from the right? Because the largest odd number must end with an odd digit.

2. Check each digit
    Convert digit character num[i] to its numeric value → (num[i] - '0').
    If it’s odd (% 2 == 1), then everything from the start up to this digit forms the largest odd number.

3. Return that prefix
    Use num.substr(0, i+1) → substring from start to that odd digit.

4. If no odd digit is found
    Return "" (empty string), because no odd number can be formed.
*/