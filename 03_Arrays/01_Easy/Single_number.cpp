#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int ans = 0;

    for (int i = 0; i < nums.size(); i++)
        ans = ans ^ nums[i];

    return ans;
}

/*
Logic:

1. Initialize result - Start with ans = 0 as the initial value.
2. XOR all elements - Go through each number in the array and XOR it with the current result (ans = ans ^ nums[i]).
3. Leverage XOR properties - The XOR operation has special mathematical properties:
a ^ a = 0 (any number XORed with itself equals 0)
a ^ 0 = a (any number XORed with 0 equals itself)
XOR is commutative and associative (order doesn't matter)
4. Automatic cancellation - Since every number except one appears exactly twice, all the duplicate pairs will cancel each other out (XOR to 0), leaving only the single number.

Example:
Input: [2,2,1,1,4]
Process: 0 ^ 2 ^ 2 ^ 1 ^ 1 ^ 4
Rearranged: (2 ^ 2) ^ (1 ^ 1) ^ 4 = 0 ^ 0 ^ 4 = 4
Result: 4 (the single number)
*/