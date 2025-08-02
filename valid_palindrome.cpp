#include <bits/stdc++.h>
using namespace std;

bool func(string s, int n, int low, int high)
{
    while (low < high && !isalnum(s[low]))
        low++;
    while (low < high && !isalnum(s[high]))
        high--;
    if (low > high)
        return true;
    if (tolower(s[low]) != tolower(s[high]))
        return false;
    return func(s, n, low + 1, high - 1);
}

bool isPalindrome(string s)
{
    int n = s.size();

    int low = 0;
    int high = n - 1;

    return func(s, n, low, high);
}