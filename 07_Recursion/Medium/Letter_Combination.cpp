#include <iostream>
#include <vector>
#include <map>
using namespace std;

void func(int idx, string temp, vector<string> &res, string digits, map<char, vector<char>> &mp, int n)
{
    if (idx == n)
    {
        res.push_back(temp);
        return;
    }
    for (int i = 0; i < mp[digits[idx]].size(); i++)
        func(idx + 1, temp + mp[digits[idx]][i], res, digits, mp, n);
}

vector<string> letterCombinations(string digits)
{
    map<char, vector<char>> mp;
    mp['2'] = {'a', 'b', 'c'};
    mp['3'] = {'d', 'e', 'f'};
    mp['4'] = {'g', 'h', 'i'};
    mp['5'] = {'j', 'k', 'l'};
    mp['6'] = {'m', 'n', 'o'};
    mp['7'] = {'p', 'q', 'r', 's'};
    mp['8'] = {'t', 'u', 'v'};
    mp['9'] = {'w', 'x', 'y', 'z'};

    vector<string> res;
    int idx = 0;
    int n = digits.size();
    string temp = "";

    if (digits.empty())
        return res;

    func(idx, temp, res, digits, mp, n);
    return res;
}

/*
1. Digit-to-Letters Map:
    Build a mapping (like a dictionary) where each digit maps to the characters on a phone keypad:
    '2' -> [a, b, c]
    '3' -> [d, e, f]
    ...
    '9' -> [w, x, y, z]

2. Recursive Function (func):
    idx = current position in the digit string.
    temp = string being formed.
    res = stores all valid combinations.

Steps inside recursion:
    Base Case: If idx == n (we’ve processed all digits), push the built string temp into res.
    Recursive Case: Look up which letters the current digit maps to, and for each letter:
    Append the letter to temp.
    Recurse to the next index (idx+1).

    3. Initial Checks:  
    If digits is empty → return an empty list.
    Otherwise, call the recursive function starting from index 0 with an empty string.
*/