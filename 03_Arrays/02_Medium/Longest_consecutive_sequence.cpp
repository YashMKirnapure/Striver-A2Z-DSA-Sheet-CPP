#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int N)
    {
        int cnt = 0;
        int res = 1;
        int lastSmaller = INT_MIN;
        sort(arr,arr+N);
        
        for(int i=0 ;i<N ;i++)
        {
            if(arr[i]-1 == lastSmaller)
            {
                cnt = cnt + 1;
                lastSmaller = arr[i];
            }
            else if(arr[i] != lastSmaller)
            {
                lastSmaller = arr[i];
                cnt = 1;
            }
            res = max(res,cnt);
        }
        return res;
    }

    /*
    Step-by-step explanation of the code:

Sort the array

The array is sorted so that all consecutive numbers come next to each other.

Example: [100, 4, 200, 1, 3, 2] → after sorting → [1, 2, 3, 4, 100, 200].

Initialize counters

cnt = 0 → keeps track of the current consecutive streak.

res = 1 → stores the maximum streak found so far.

lastSmaller = INT_MIN → keeps track of the last number in the sequence.

Iterate through the array
For each number arr[i]:

Case 1: If it continues the sequence
If arr[i] - 1 == lastSmaller, it means arr[i] is just one greater than the last number.
→ Increment cnt (current streak length).
→ Update lastSmaller = arr[i].

Case 2: If it’s a duplicate
If arr[i] == lastSmaller, do nothing (skip it).
This prevents duplicates from breaking the streak.

Case 3: If it breaks the sequence
If arr[i] is not consecutive with lastSmaller,
→ Reset cnt = 1 (start a new streak).
→ Update lastSmaller = arr[i].

Update result
After each step, update res = max(res, cnt) so the maximum streak is always stored.

Return the result
Finally, return res, which is the length of the longest consecutive subsequence.
    */