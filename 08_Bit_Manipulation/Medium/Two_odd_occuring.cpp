#include <iostream>
#include <vector>
using namespace std;

vector<int> twoOddNum(vector<int> &arr)
{
    int n = arr.size();
    int b1 = 0;
    int b2 = 0;

    long long Xorval = 0;
    for (int i = 0; i < n; i++)
        Xorval = Xorval ^ arr[i];

    int rightMost = (Xorval & Xorval - 1) ^ Xorval;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] & rightMost)
            b1 = b1 ^ arr[i];
        else
            b2 = b2 ^ arr[i];
    }
    if (b1 > b2)
        return {b1, b2};
    return {b2, b1};
}

/*
1. XOR all elements of the array

int xorAll = 0;
for (int x : arr)
    xorAll ^= x;

Since XOR cancels out pairs (a ^ a = 0), all even occurring numbers vanish.
Result = xorAll = num1 ^ num2 (the two odd occurring numbers XORed).

2. Find a differentiating bit

int rightmostSetBit = xorAll & ~(xorAll - 1);

rightmostSetBit extracts the lowest bit where num1 and num2 differ.
This helps split numbers into two groups.

3. Partition numbers into two groups

int res1 = 0, res2 = 0;
for (int x : arr) {
    if (x & rightmostSetBit)
        res1 ^= x;
    else
        res2 ^= x;
}

All numbers are divided into two groups based on whether they have that bit set.
Since duplicates cancel out again, res1 and res2 end up being the two odd occurring numbers.

:-Example
Array = [4, 3, 4, 4, 4, 5, 5, 7, 3, 9]

XOR of all = 7 ^ 9 = 14
Rightmost set bit = 2 (binary 1110)
Partition:
    Group 1 (bit set): gives 7
    Group 2 (bit not set): gives 9
Answer = (7, 9)
*/