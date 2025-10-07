#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int> &arr)
{
    int n = arr.size();
    int lMax = 0;
    int rMax = 0;
    int total = 0;
    int l = 0;
    int r = n - 1;

    while (l < r)
    {
        if (arr[l] <= arr[r])
        {
            if (lMax > arr[l])
                total += lMax - arr[l];
            else
                lMax = arr[l];
            l = l + 1;
        }
        else
        {
            if (rMax > arr[r])
                total += rMax - arr[r];
            else
                rMax = arr[r];
            r = r - 1;
        }
    }
    return total;
}

/*
1. Goal:
Given an array where each element represents the height of a bar,
find how much rainwater can be trapped between them after it rains.

2. Key Idea:
Water trapped above a bar depends on the minimum of the tallest bars to its left and right.

Formula:
water[i] = min(leftMax[i], rightMax[i]) - height[i]

But computing leftMax and rightMax arrays separately takes extra space —
so we use the two-pointer trick instead! ⚡

3. Initialize:
    l = 0 (left pointer), r = n - 1 (right pointer)
    lMax = 0, rMax = 0 (track tallest bars seen so far)
    total = 0 (store total trapped water)

4. Move the smaller side inward each time:
    If arr[l] <= arr[r] →
        The left side limits the water level.
        If arr[l] < lMax, some water can be trapped → total += lMax - arr[l].
        Else, update lMax = arr[l].
        Move l++.
    Else →
        The right side limits the water level.
        If arr[r] < rMax, some water can be trapped → total += rMax - arr[r].
        Else, update rMax = arr[r].
        Move r--.

5. Continue until l meets r.
    At the end, total contains the total trapped rainwater.
*/