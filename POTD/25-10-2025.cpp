#include <iostream>
using namespace std;

int totalMoney(int n)
{
    if (n <= 7)
        return n * (n + 1) / 2;

    int idx = 0;
    int sum = 0;

    while (n > 7)
    {
        for (int i = 1; i <= 7; i++)
            sum += i + idx;
        idx++;
        n = n - 7;
    }

    for (int i = 0; i < n; i++)
    {
        idx++;
        sum += idx;
    }

    return sum;
}