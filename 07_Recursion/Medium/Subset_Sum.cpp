#include <iostream>
#include <vector>
using namespace std;

void func(vector<int> &res, int idx, int sum, vector<int> &arr, int n)
{
    if (idx == n)
    {
        res.push_back(sum);
        return;
    }

    // Pick
    func(res, idx + 1, sum + arr[idx], arr, n);

    // Not Pick
    func(res, idx + 1, sum, arr, n);
}

vector<int> subsetSums(vector<int> &arr)
{
    int sum = 0;
    int idx = 0;
    int n = arr.size();
    vector<int> res;
    func(res, idx, sum, arr, n);
    return res;
}

/*
1. You’re given an array of numbers, and you want to find the sum of every possible subset of that array.
    Subset = any selection of elements (including empty set).

2. Start recursion at index 0 with sum = 0.

3. At each index, you have two choices:
    Pick the current number → add it to sum and move to the next index.
    Not pick → keep sum as it is and move to the next index.

4. Once you reach the end (idx == n), record the sum into res.
5. At the end, res will contain all possible subset sums.
*/