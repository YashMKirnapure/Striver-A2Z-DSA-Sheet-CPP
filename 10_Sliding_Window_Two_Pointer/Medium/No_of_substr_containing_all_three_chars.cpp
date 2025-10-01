#include <iostream>
#include <unordered_map>
using namespace std;

int numberOfSubstrings(string str)
{
    int n = str.size();
    int left = 0;
    int right = 0;
    int cnt = 0;
    unordered_map<char, int> mp;

    while (right < n)
    {
        mp[str[right]]++;
        while (mp['a'] >= 1 && mp['b'] >= 1 && mp['c'] >= 1)
        {
            cnt += (n - right);
            mp[str[left]]--;
            left++;
        }
        right++;
    }
    return cnt;
}