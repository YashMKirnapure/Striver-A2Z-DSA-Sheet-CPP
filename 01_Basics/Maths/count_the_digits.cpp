#include <bits/stdc++.h>
using namespace std;

int countDigit(int n) 
{
    if(n == 0)
        return 1;

    int cnt = 0;

    while(n>0)
    {
        cnt++;
        n = n/10;
    }
    return cnt;
}

