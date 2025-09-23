#include <iostream>
#include <vector>
using namespace std;

bool isValidStr(string temp, int idx)
{
    if (idx == temp.size())
        return true;
    if (idx > 0 && temp[idx] == '1' && temp[idx - 1] == '1')
        return false;
    return isValidStr(temp, idx + 1);
}

void func(vector<string> &res, string temp, int N)
{
    if (temp.size() == N)
    {
        if (isValidStr(temp, 0))
        {
            res.push_back(temp);
            return;
        }
        return;
    }

    // Try for 0
    func(res, temp + '0', N);

    // Try for 1
    func(res, temp + '1', N);
}

vector<string> generateBinaryStrings(int N)
{
    vector<string> res;
    string temp;
    func(res, temp, N);
    return res;
}

/*
Step 1: func(res, temp, N)
    Builds binary strings step by step.
    Base case: when temp.size() == N
        If isValidStr(temp, 0) → push into results.
        Else, discard.

Step 2: isValidStr(temp, idx)
    Recursively checks if the string has no two consecutive 1s.
    Rule: if temp[idx] == '1' and previous was also 1 → invalid.
    Else → keep checking next index.

Step 3: Recursive Expansion
    At each step, you try both:
        Add '0' → always safe.
        Add '1' → may or may not be valid depending on neighbors (checked later).
This ensures all strings are explored.
*/