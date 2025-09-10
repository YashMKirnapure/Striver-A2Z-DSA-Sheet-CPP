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