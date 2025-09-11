#include <iostream>
#include <map>
using namespace std;

int romanToInt(string s)
{
    int n = s.size();
    map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    int res = 0;

    for (int i = 0; i < n-1; i++)
    {
        if (mp[s[i]] < mp[s[i + 1]])
            res = res - mp[s[i]];
        else
            res = res + mp[s[i]];
    }
    return res;
}

/*
1. Setup values of Roman numerals
    We store the value of each Roman symbol in a map:
    I=1, V=5, X=10, L=50, C=100, D=500, M=1000.

2. Iterate over the string
    Normally, we add the value of each Roman character.
    But! Roman numerals have subtraction rules, like:
    IV = 4 (5 − 1),
    IX = 9 (10 − 1),    
    XL = 40 (50 − 10),
    CM = 900 (1000 − 100).

    3. Check subtraction case
For each character s[i]:
If its value is less than the next one (mp[s[i]] < mp[s[i+1]]), then it’s a subtraction case → subtract its value.
Else → add its value.

4. Final result
    After processing the entire string, res is the integer equivalent.

--- Example ---
s = "MCMXCIV"

M = 1000, next C=100 → 1000 ≥ 100 → add → res = 1000
C = 100, next M=1000 → 100 < 1000 → subtract → res = 900
M = 1000, next X=10 → add → res = 1900
X = 10, next C=100 → subtract → res = 1890
C = 100, next I=1 → add → res = 1990
I = 1, next V=5 → subtract → res = 1989
V = 5, end → add → res = 1994

Answer = 1994
*/

