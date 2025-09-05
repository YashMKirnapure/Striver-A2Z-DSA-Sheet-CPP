#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& a, long long k) 
{
    int n = a.size(); // size of the array.

    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) 
    {
        //calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        long long rem = sum - k;

        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}


/*
Logic:

1. Use prefix sum technique - Keep a running sum of elements from the beginning and store these prefix sums in a map along with their first occurrence index.
2. Track cumulative sum - For each element, add it to the running sum (this represents sum from index 0 to current index).
3. Check if entire prefix equals k - If the current prefix sum equals k, then the subarray from index 0 to current index has sum k. Update maximum length.
4. Use the key insight - If we want a subarray ending at current index i with sum k, we need:
sum[0 to i] - sum[0 to j] = k
Which means sum[0 to j] = sum[0 to i] - k
So we look for rem = sum - k in our map
5. Calculate subarray length - If we find rem in the map at index j, then subarray from j+1 to i has sum k, with length i - j.
6. Store only first occurrence - Only add a prefix sum to the map if it hasn't been seen before, ensuring we get the longest possible subarray.

Example:
Input: [1,2,3,1,1,1,1] with k = 3
At index 2: sum=6, rem=3, found at index -1 (implicit), length = 3
At index 1: sum=3, equals k directly, length = 2
Result: Length 3 for subarray [1,2] or [3]

Key insight: This uses the mathematical property that if prefix sums at two different positions differ by k, then the subarray between them has sum k.
*/
