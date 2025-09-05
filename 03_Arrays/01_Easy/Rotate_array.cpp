#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> res(n);

    for (int i = 0; i < n; i++)
        res[(i + k) % n] = nums[i];

    nums = res;
}

/*
Logic:

1. Create a temporary array - Make a new array res of the same size to store the rotated elements.
2. Calculate new positions - For each element at position i, calculate where it should go after left rotation using the formula (i + k) % n.
3. The key formula - (i + k) % n moves each element k positions to the right (which achieves left rotation of the array):

Elements near the end wrap around to the beginning due to the modulo operation
This effectively shifts the entire array content to the left by k positions

4. Copy back - Replace the original array with the rotated result.

Example:

Input: [1,2,3,4,5] with k = 2
Element at index 0 (value 1) goes to position (0+2)%5 = 2
Element at index 1 (value 2) goes to position (1+2)%5 = 3
Element at index 3 (value 4) goes to position (3+2)%5 = 0
Element at index 4 (value 5) goes to position (4+2)%5 = 1
Result: [4,5,1,2,3] (original array shifted left by 2)
*/
