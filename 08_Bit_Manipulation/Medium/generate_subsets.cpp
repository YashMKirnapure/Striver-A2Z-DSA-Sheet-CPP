#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size();
    int subsetSize = 1 << n;
    vector<vector<int>> ans;

    for (int i = 0; i < subsetSize; i++)
    {
        vector<int> res;
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
                res.push_back(nums[j]);
        }
        ans.push_back(res);
    }
    return ans;
}

/*
Goal: Generate all possible subsets of an array of size n.

Key idea: Each subset can be represented by a bitmask of length n:
0 → element not included
1 → element included

Step 1: Total subsets
int subsetSize = 1 << n;

There are 2^n possible subsets.
1 << n is literally 2^n.

Step 2: Iterate over all masks
for (int i = 0; i < subsetSize; i++) {
    ...
}
Each i (from 0 to 2^n - 1) represents a subset in binary form.

Step 3: Pick elements based on set bits
if ((i >> j) & 1) res.push_back(nums[j]);

Right shift i by j → brings j-th bit to the rightmost position.
AND with 1 → check if that bit is set.
If yes, include nums[j] in the subset.

Step 4: Collect results
After inner loop, res is one subset.
Push it into ans.

Example
nums = [1,2,3]
Binary masks:
000 → {}
001 → {1}
010 → {2}
011 → {1,2}
100 → {3}
101 → {1,3}
110 → {2,3}
111 → {1,2,3}
*/