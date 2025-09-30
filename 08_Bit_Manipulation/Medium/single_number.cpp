#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int n = nums.size();
    int res = 0;

    for (int x : nums)
        res = res ^ x;

    return res;
}

/*
Problem: Given a list where every number appears twice except one, find that single number.

Key idea:
XOR has properties:
    a ^ a = 0 (a number cancels itself out)
    a ^ 0 = a
    XOR is both commutative and associative (order doesn’t matter).

Looping through the array:
res = res ^ x;

Every pair cancels out to 0.
The number that appears once will remain in res.
*/