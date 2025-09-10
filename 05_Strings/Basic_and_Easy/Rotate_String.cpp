#include <iostream>
using namespace std;

bool rotateString(string s1, string s2)
{
    string s3 = s1 + s1;

    if (s1.size() != s2.size())
        return false;

    return s3.find(s2) != string::npos;
}

/*
1. Check lengths first
    If s1 and s2 don’t have the same length → they can’t be rotations of each other.
    Example: "abc" vs "ab" → immediately false.

2. Form a doubled string
    Create s3 = s1 + s1.
    Why? Because any rotation of s1 will always appear as a substring inside s1 + s1.
    Example:
    s1 = "abcd" → s3 = "abcdabcd".
    Rotations: "abcd", "bcda", "cdab", "dabc".
    All are substrings of "abcdabcd".

3. Check if s2 exists inside s3
    Use s3.find(s2).
    If found (!= string::npos) → s2 is a valid rotation of s1.
    Otherwise → not a rotation.
*/