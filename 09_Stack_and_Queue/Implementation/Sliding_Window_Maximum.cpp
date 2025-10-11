#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> res;
    deque<int> dq;

    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1)
            res.push_back(nums[dq.front()]);
    }
    return res;
}

/*
1. We maintain a deque (double-ended queue) to store indices of useful elements in the current window.

2. The deque is always monotonically decreasing (values from front → back are in decreasing order).

3. For each element:
    Remove out-of-window elements: if the front index ≤ i - k, pop it.
    
    Maintain decreasing order: pop all elements from the back that are smaller than or equal to nums[i] (since they can never be max again).
    
    Push current index.
    
    Record max: when we’ve processed at least k elements (i ≥ k - 1), the front of the deque holds the index of the maximum for the current window.

Example:

Let’s take
nums = [1, 3, -1, -3, 5, 3, 6, 7], k = 3

Step	Window	Deque(values)	Max
1	    [1]	        [1]	         -
2	    [1, 3]	    [3]	         -
3	    [1, 3, -1]	[3, -1]	     3
4	    [3, -1, -3]	[3, -1, -3]	 3
5	    [-1, -3, 5]	[5]	         5
6	    [-3, 5, 3]	[5, 3]	     5
7	    [5, 3, 6]	[6]	         6 
8	    [3, 6, 7]	[7]	         7

✅ Output: [3, 3, 5, 5, 6, 7]

*/