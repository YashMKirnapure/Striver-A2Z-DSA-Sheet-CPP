#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) 
{
    long long revNo = 0;
    long long ogNo = x;

    if(x < 0)
        return false;

    while(x != 0)
    {
        int rem = x % 10;
        revNo = revNo * 10 + rem;
        x = x / 10;
    }
    
    return revNo == ogNo;

}