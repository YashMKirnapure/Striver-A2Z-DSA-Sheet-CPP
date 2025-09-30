#include <bits/stdc++.h>
using namespace std;

// Brute Force
string toBinary(int temp)
{
    string res = "";
    while (temp > 0)
    {
        if (temp % 2 == 0)
            res = res + '0';
        else
            res = res + '1';
        temp = temp >> 1;
    }
    reverse(res.begin(), res.end());
    return res;
}

int minBitFlips(int start, int goal)
{
    string startStr = toBinary(start);
    string goalStr = toBinary(goal);

    int cnt = 0;
    int n = max(startStr.size(), goalStr.size());

    while (startStr.size() < n)
        startStr = "0" + startStr;
    while (goalStr.size() < n)
        goalStr = "0" + goalStr;

    for (int i = 0; i < n; i++)
    {
        if (startStr[i] != goalStr[i])
            cnt++;
    }

    return cnt;
}

// Optimal
int minBitFlips(int start, int goal)
{
    int cnt = 0;
    int num = start ^ goal;

    while (num != 0)
    {
        if (num != 0)
        {
            cnt++;
            num = num & (num - 1);
        }
    }
    return cnt;
}

/*
The task is to find how many bits need to be flipped to convert start into goal.

Step 1:
int num = start ^ goal;

XOR gives 1 wherever the bits of start and goal differ.
So now num is a binary mask of all differing positions.

Step 2:
while(num != 0) {
    cnt++;
    num = num & (num - 1);
}

This loop counts how many set bits are in num.
num & (num - 1) removes the last set bit each time.
Each removal increments cnt, which is our number of flips needed.

Final result = number of differing bits between start and goal.
*/