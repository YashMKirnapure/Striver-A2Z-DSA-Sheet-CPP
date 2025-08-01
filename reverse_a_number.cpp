#include <bits/stdc++.h>
using namespace std;

int reverse(int x) 
{
    long long num = 0;    
    int c1 = INT_MIN;
    int c2 = INT_MAX-1;

    while(x != 0)
    {
        int rem = x%10;
        num = num * 10 + rem;
        x = x / 10;
    }

    if(num > c2 || num < c1)
        return 0;
    return num;
}