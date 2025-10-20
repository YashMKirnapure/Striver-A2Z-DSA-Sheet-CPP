#include <iostream>
using namespace std;

int findMin(int num)
{
    int coins = 0;

    coins += num / 10;
    num = num % 10;

    coins += num / 5;
    num = num % 5;

    coins += num / 2;
    num = num % 2;

    if (num == 1)
        coins++;

    return coins;
}