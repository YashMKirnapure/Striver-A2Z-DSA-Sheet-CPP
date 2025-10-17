//LC 3003. Maximize the Number of Partitions After Operations 

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string S;
    int K;
    int solve(int i, long long uniqueChars, bool canChange)
    {
        if (i >= S.size())
            return 0;
        int charIndex = S[i] - 'a';
        int newUniqueChars = uniqueChars | (1 << charIndex);
        int uniqueCharCount = __builtin_popcount(newUniqueChars);

        int result;

        if (uniqueCharCount > K)
        {
            result = 1 + solve(i + 1, 1 << charIndex, canChange);
        }
        else
        {
            result = solve(i + 1, newUniqueChars, canChange);
        }

        if (canChange == true)
        {
            for (int newCharIndex = 0; newCharIndex < 26; newCharIndex++)
            {
                int newCharSet = uniqueChars | (1 << newCharIndex);
                int newUniqueCharCount = __builtin_popcount(newCharSet);

                if (newUniqueCharCount > K)
                {
                    result = max(result, 1 + solve(i + 1, 1 << newCharIndex, false));
                }
                else
                {
                    result = max(result, solve(i + 1, newCharSet, false));
                }
            }
        }
        return result;
    }

    int maxPartitionsAfterOperations(string s, int k)
    {
        S = s;
        K = k;
        return solve(0, 0, true) + 1;
    }
};

//Memoization
class Solution {
public:
    unordered_map<long long,int>mp;
    string S;
    int K;
    int solve(long long i, long long uniqueChars, bool canChange) {
        long long key = ((i<<27) | (uniqueChars<<1) | canChange);

        if(mp.find(key)!=mp.end())
            return mp[key];

        if (i >= S.size())
            return 0;
        int charIndex = S[i] - 'a';
        int newUniqueChars = uniqueChars | (1 << charIndex);
        int uniqueCharCount = __builtin_popcount(newUniqueChars);

        int result;

        if (uniqueCharCount > K) {
            result = 1 + solve(i + 1, 1 << charIndex, canChange);
        } else {
            result = solve(i + 1, newUniqueChars, canChange);
        }

        if (canChange == true) {
            for (int newCharIndex = 0; newCharIndex < 26; newCharIndex++) {
                int newCharSet = uniqueChars | (1 << newCharIndex);
                int newUniqueCharCount = __builtin_popcount(newCharSet);

                if (newUniqueCharCount > K) {
                    result = max(result, 1 + solve(i + 1, 1 << newCharIndex, false));
                } else {
                result = max(result,solve(i+1,newCharSet,false));
                }
            }
        }
        return mp[key] = result;
    }

    int maxPartitionsAfterOperations(string s, int k) {
        S = s;
        K = k;
        return solve(0, 0, true)+1;
    }
};
