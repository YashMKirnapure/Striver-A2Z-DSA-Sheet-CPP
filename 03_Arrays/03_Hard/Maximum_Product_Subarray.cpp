#include <bits/stdc++.h>
using namespace std;

// Method 1
int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    int maxy = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int prod = 1;
        for (int j = i; j < n; j++)
        {
            prod = prod * nums[j];
            maxy = max(prod, maxy);
        }
    }
    return maxy;
}

// Method 2
int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    int maxy = INT_MIN;

    int pre = 1;
    int suff = 1;

    for (int i = 0; i < n; i++)
    {
        if (pre == 0)
            pre = 1;
        if (suff == 0)
            suff = 1;

        pre = pre * nums[i];
        suff = suff * nums[n - i - 1];

        maxy = max(maxy, max(pre, suff));
    }
    return maxy;
}

/*
Products can flip signs when negatives are involved.

Zeros reset the product.

To catch all possibilities, we scan:

Left to right (prefix)

Right to left (suffix)

Because the max product subarray could "start" or "end" after a zero or a negative number.
*/