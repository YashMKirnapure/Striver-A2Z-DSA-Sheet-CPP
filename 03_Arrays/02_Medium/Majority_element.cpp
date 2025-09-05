#include <bits/stdc++.h>
using namespace std;

int majorityElement_1(vector<int> &nums)
{
    int n = nums.size();
    int maxy = -1;
    int cnt = 0;

    sort(nums.begin(), nums.end());

    return nums[(n / 2)];
}

int majorityElement_2(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
        mp[nums[i]]++;

    for (auto x : mp)
    {
        if (x.second > n / 2)
            return x.first;
    }
    return 1;
}

int majorityElement(vector<int> &nums) {
    int candidate = 0;
    int count = 0;
    
    // Phase 1: Find potential candidate
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        
        if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }
    
    // Phase 2: Verify candidate (optional if majority is guaranteed)
    count = 0;
    for (int num : nums) {
        if (num == candidate) {
            count++;
        }
    }
    
    return (count > nums.size() / 2) ? candidate : -1;
}

/*
Why Boyer-Moore is Optimal:
Time Complexity: O(n) - single pass through array
Space Complexity: O(1) - only uses two variables
Logic in Natural Language:

Voting mechanism - Imagine each element "votes" for itself. The majority element will outnumber all others combined.
Candidate selection - Start with any element as candidate. For each element:

If count is 0, make current element the new candidate
If current element matches candidate, increment count (vote for)
If current element differs from candidate, decrement count (vote against)


Key insight - When count reaches 0, it means equal numbers of different elements have "cancelled out". The majority element will survive this process.
Verification (optional) - Count occurrences of the final candidate to confirm it's truly the majority.

Example:

Input: [2,2,1,1,1,2,2]
Process: candidate changes but majority element (2) eventually wins
Result: Returns 2
*/
