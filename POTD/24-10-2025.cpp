#include <iostream>
#include <vector>
using namespace std;

bool balanced(int num)
{
    vector<int> count(10);

    while (num > 0)
    {
        int dig = num % 10;
        count[dig]++;
        num = num / 10;
    }

    for (int digit = 0; digit < 10; digit++)
    {
        if (count[digit] > 0 && count[digit] != digit)
            return false;
    }
    return true;
}

int nextBeautifulNumber(int n)
{
    for (int i = n + 1; i <= 1224444; i++)
    {
        if (balanced(i))
            return i;
    }
    return -1;
}

