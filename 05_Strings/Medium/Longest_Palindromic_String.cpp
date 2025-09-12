#include <iostream>
using namespace std;

string expand(string str, int left, int right)
{
    while (left >= 0 && right < str.size() && str[left] == str[right])
    {
        left--;
        right++;
    }
    return str.substr(left + 1, right - left - 1);
}

string longestPalindrome(string str)
{
    int n = str.size();
    string ans;

    if (n <= 1) 
        return str;

    for (int i = 0; i < n; i++)
    {
        string odd = expand(str, i, i);
        string even = expand(str, i, i + 1);

        if (odd.size() > ans.size())
            ans = odd;
        if (even.size() > ans.size())
            ans = even;
    }
    return ans;
}

/*
1. A palindrome mirrors around its center.
    Odd length → single character center.
    Even length → two-character center.

2. For each index i:
    Expand around i (odd-length palindrome).
    Expand around i and i+1 (even-length palindrome).

3. Keep track of the longest palindrome found so far.
*/