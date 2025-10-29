#include <iostream>
using namespace std;

bool check(int num)
{
    while (num > 0)
    {
        int dig = num % 2;
        if (dig != 1)
            return false;
        num = num / 2;
    }
    return true;
}

int smallestNumber(int n)
{
    for (int i = n; i < i + 1; i++)
    {
        if (check(i))
            return i;
    }
    return 1;
}

// M-2
int smallestNumber(int n)
{
    int temp = 1;
    while (temp <= n)
    {
        temp = temp * 2;
    }
    return temp - 1;
}

// M-3
int smallestNumber(int n)
{
    int x = 0;
    while (n > 0)
    {
        x++;
        n = n / 2;
    }
    return pow(2, x) - 1;
}