#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> res;
    int n = intervals.size();

    if (n == 0)
        return res;

    sort(intervals.begin(), intervals.end());

    vector<int> current = intervals[0];

    for (int i = 1; i < n; i++)
    {
        if (current[1] >= intervals[i][0])
            current[1] = max(current[1], intervals[i][1]);
        else
        {
            res.push_back(current);
            current = intervals[i];
        }
    }
    res.push_back(current);
    return res;
}

/*
Step-by-step logic:

Sort the intervals

First, you sort all intervals by their starting time.

This ensures that any overlapping intervals will appear next to each other.

Track the current interval

Take the first interval as current (the one you’ll try to merge with others).

Iterate through the rest

For each interval:

If it overlaps with current (current[1] >= intervals[i][0]), merge them by updating the end of current:
current[1] = max(current[1], intervals[i][1]);

If it does not overlap, then current is complete:

Push it into the result list (res.push_back(current)).

Start a new current with the next interval.

Push the last interval

After finishing the loop, add the final current interval to the result.

 Example:

Input:

intervals = [[1,3],[2,6],[8,10],[15,18]]

Process:

Sort → [[1,3],[2,6],[8,10],[15,18]]

Start with [1,3]

Overlaps with [2,6] → merge → [1,6]

[8,10] doesn’t overlap → push [1,6], now current = [8,10]

[15,18] doesn’t overlap → push [8,10], then push [15,18]

Output:

[[1,6],[8,10],[15,18]]


Complexity:

Sorting: O(n log n)

Merge loop: O(n)

Overall: O(n log n)
*/